//
// zlli@telenav.cn
//
#include "eglhelper.h"

EglHelper::EglHelper()
{
	m_display = EGL_NO_DISPLAY;
	m_surface = EGL_NO_SURFACE;
	m_error = "";
}
EglHelper::~EglHelper()
{
	if(m_display!=EGL_NO_DISPLAY){
	    eglTerminate(m_display);
	}
}

std::string EglHelper::GetEglError()
{
	return m_error;
}

void EglHelper::ChooseConfig()
{
	EGLConfig config;
	// make attr is RGBA to make sure glReadPixels faster
	EGLint attrs[] = {
			EGL_RED_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_BLUE_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_NONE };
	EGLint config_num;
	EGLBoolean eglre = eglChooseConfig(m_display, attrs, &config, 1, &config_num);
	if ((eglre)&&(config_num > 0)) {

	} else {
		AddErrorMessage("eglChooseConfig() error");
		return;
	}
	m_config = config;
}
void EglHelper::CreateOpenglContext(NativeDisplayType nativeDisplay)
{
	EGLDisplay display = eglGetDisplay(nativeDisplay);
	if (display == EGL_NO_DISPLAY) {
		AddErrorMessage("eglGetDisplay() get EGL_NO_DISPLAY");
		return;
	}
	m_display = display;
	EGLBoolean eglre = eglInitialize(m_display, 0, 0);
	if (eglre != EGL_TRUE) {
		AddErrorMessage("eglInitialize() error");
		return;
	}
	//
	ChooseConfig();
	//
	EGLContext context = eglCreateContext(m_display, m_config, EGL_NO_CONTEXT,
			NULL);
	if (context == EGL_NO_CONTEXT) {
		AddErrorMessage("eglCreateContext() error");
		return;
	}
	m_context = context;
}
void EglHelper::CreatePbuffer(int w,int h)
{
	EGLint pbattrs[] = { EGL_WIDTH, w, EGL_HEIGHT, h, EGL_NONE };
	EGLSurface surface = eglCreatePbufferSurface(m_display, m_config, pbattrs);
	if (surface == EGL_NO_SURFACE) {
		AddErrorMessage("eglCreatePbufferSurface() return EGL_NO_SURFACE");
		return ;
	}
	m_surface = surface;


}
void EglHelper::SwapBuffer()
{
	EGLBoolean re = eglSwapBuffers(m_display,m_surface);
	if(!re){
		AddErrorMessage("eglSwapBuffers() error");
	}
}
void EglHelper::MakeCurrent(bool flag){
	if(flag) {
		eglMakeCurrent(m_display,m_surface,m_surface,m_context);
	}else {
		eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	}
}
void EglHelper::AddErrorMessage(const char* str)
{
	m_error += "EglHelper - ";
	m_error += str ;
	m_error += "\n";
}
