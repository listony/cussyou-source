
#ifndef SHADER_H
#define SHADER_H

#include <GLES2/gl2.h>

#ifdef __cplusplus
extern "C" {
#endif 

GLuint load_shader(GLenum shaderType, const char* pSource);
GLuint create_program(const char* pVertexSource, const char* pFragmentSource);

/*!
  this is util function simplely create an shader program with built in shaders.
  you must set vertex positon with attr "vPosition" in app program.
 */
GLuint create_simple_program();

#ifdef __cplusplus
}
#endif 


#endif

