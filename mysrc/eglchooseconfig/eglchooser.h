#ifndef EGL_CHOOSER_H
#define EGL_CHOOSER_H

#include <EGL/egl.h>

struct EglConfigChooser {
  int red;
  int green;
  int blue;
  int alpha;
  int depth;
  int stencil;
  // add more if necessary
};

void EglConfigChooser_init(struct EglConfigChooser* chooser);

int EglConfigChooser_findConfigAttrib(EGLDisplay display, EGLConfig config, int attribute, int defaultValue);

EGLConfig EglConfigChooser_chooseEglConfig(
			  EGLDisplay dispaly,
			  struct EglConfigChooser* chooser,
			  EGLConfig* configs,
			  int configsNum				 
			  );

#endif
