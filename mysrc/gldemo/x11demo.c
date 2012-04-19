/*
  The first version is from 
  http://www.opengl.org/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib
 */
#include<stdio.h>
#include<stdlib.h>
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>

Display                 *dpy;
Window                  root;
GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
XVisualInfo             *vi;
Colormap                cmap;
XSetWindowAttributes    swa;
Window                  win;
GLXContext              glc;
XWindowAttributes       gwa;
XEvent                  xev;

static void DrawTestTriangle(int w,int h)
{
	static float tri[] = {
			-1.0, -1.0, 0.0,
			 1.0, -1.0, 0.0,
			 0.0,  1.0, 0.0
	};
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustumf(-1.0,1.0,-1.0,1.0,1.0,100.0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1,0.1,0.1,1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0,0.0,-2.0);

    glEnableClientState(GL_VERTEX_ARRAY);

    // draw a texture
    glVertexPointer(3,GL_FLOAT,0,tri);

    glColor4f(1.0,1.0,1.0,1.0);
    glDrawArrays(GL_TRIANGLE_STRIP,0,3);
    glDisableClientState(GL_VERTEX_ARRAY);
}

 
int main(int argc, char *argv[]) {

  dpy = XOpenDisplay(NULL); 
  if(dpy == NULL) {
    printf("\n\tcannot connect to X server\n\n");
    exit(0); }
        
  root = DefaultRootWindow(dpy);

  vi = glXChooseVisual(dpy, 0, att);

  if(vi == NULL) {
    printf("\n\tno appropriate visual found\n\n");
    exit(0); } 
  else {
    printf("\n\tvisual %p selected\n", (void *)vi->visualid); 
  }/* %p creates hexadecimal output like in glxinfo */


  cmap = XCreateColormap(dpy, root, vi->visual, AllocNone);

  swa.colormap = cmap;
  swa.event_mask = ExposureMask | KeyPressMask;

  win = XCreateWindow(dpy, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);

  XMapWindow(dpy, win);
  XStoreName(dpy, win, "VERY SIMPLE APPLICATION");
 
  /* create gl context */
  /* need to replaced by  gl es context */
  glc = glXCreateContext(dpy, vi, NULL, GL_TRUE);
  glXMakeCurrent(dpy, win, glc);
  /* end create context */
  glEnable(GL_DEPTH_TEST); 
 
  while(1) {
    XNextEvent(dpy, &xev);
        
    if(xev.type == Expose) {
      XGetWindowAttributes(dpy, win, &gwa);
      DrawTestTriangle(gwa.width, gwa.height);
      glXSwapBuffers(dpy, win); }
                
    else if(xev.type == KeyPress) {
      glXMakeCurrent(dpy, None, NULL);
      glXDestroyContext(dpy, glc);
      XDestroyWindow(dpy, win);
      XCloseDisplay(dpy);
      exit(0); }
  } /* this closes while(1) { */
} /* this is the } which closes int main(int argc, char *argv[]) { */
