#include <stdlib.h>
#include <math.h>
#include "eglchooser.h"
#include "NPLog.h"

void EglConfigChooser_init(struct EglConfigChooser* chooser)
{
  memset(chooser,0,sizeof(struct EglConfigChooser));
}

int EglConfigChooser_findConfigAttrib(EGLDisplay display, EGLConfig config, int attribute, int defaultValue)
{
  int value;
  if(eglGetConfigAttrib(display,config,attribute,&value)){
    return value;
  }
  return defaultValue;
}
// refer GLViewSurface.java ^_^
EGLConfig EglConfigChooser_chooseEglConfig(
			  EGLDisplay display,
			  struct EglConfigChooser* chooser,
			  EGLConfig* configs,
			  int configsNum
			  )
{
  EGLConfig chooseConfig = NULL;
  int chooseDistance = 10000;
  for(int i=0;i<configsNum;i++){
    int r = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_RED_SIZE,0);
    int g = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_RED_SIZE,0);
    int b = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_BLUE_SIZE,0);
    int a = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_ALPHA_SIZE,0);
    int d = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_DEPTH_SIZE,0);
    int s = EglConfigChooser_findConfigAttrib(display,configs[i],EGL_STENCIL_SIZE,0);
    int dis;
    dis = abs(r-chooser->red) +
      abs(g - chooser->green) +
      abs(b - chooser->blue) +
      abs(a - chooser->alpha) +
      abs(d - chooser->depth) +
      abs(s - chooser->stencil) ;
    if(dis < chooseDistance ){
      chooseDistance = dis;
      chooseConfig = configs[i];
    }
    NPLogPrintf("%d: r,g,b,a,d,s=%d,%d,%d,%d,%d,%d",i,r,g,b,a,d,s);
  }
  return chooseConfig;
}
