//
// zlli@telenav.cn
//
#ifndef EGL_HELPER_H
#define EGL_HELPER_H
#include <EGL/egl.h>
#include <string>

class EglHelper {
public:
	EglHelper();
	~EglHelper();
public:


	void CreateOpenglContext(NativeDisplayType nativeDisplay);

	//! create an pbuffer
	//! \param w width
	//! \param h height
	void CreatePbuffer(int w,int h);

	//! make current or not by param flag
	void MakeCurrent(bool flag);

	void SwapBuffer();

	//! get the error message
	std::string GetEglError();
private:
	void AddErrorMessage(const char* str);
	void ChooseConfig();
private:
	EGLSurface m_surface;
	EGLDisplay m_display;
	EGLContext m_context;
	EGLConfig m_config;
	std::string m_error;
};

#endif
