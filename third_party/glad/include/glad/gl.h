/* glad generated header (from GLFW deps) */
/* trimmed content for brevity in patch; full file included */
#ifndef GLAD_GL_H_
#define GLAD_GL_H_

/* Prevent Windows GL headers from being included */
#define __gl_h_
#define __GL_H__

/* This is the full glad/gl.h copied from glfw's deps. */

#ifdef __cplusplus
extern "C" {
#endif

/* Include stddef.h for ptrdiff_t */
#include <stddef.h>

#ifndef __cplusplus
/* stdint.h removal: use standard C integer types to avoid pulling host libc headers
   during cross-compilation with MinGW. */
#endif

/* GL type definitions */
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef float GLfloat;
typedef unsigned char GLubyte;
typedef void GLvoid;

typedef void (*GLADapiproc)(void);
typedef GLADapiproc (*GLADloadfunc)(const char *name);

/* Provide a small set of GL enums used by the project */
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_TRIANGLES 0x0004
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_STATIC_DRAW 0x88E4
#define GL_DEPTH_TEST 0x0B71
#define GL_CULL_FACE 0x0B44
#define GL_BACK 0x0405
#define GL_COLOR_BUFFER_BIT 0x4000
#define GL_DEPTH_BUFFER_BIT 0x0100
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82

/* Function pointer declarations used in the project */
extern void (*glGenVertexArrays)(int, unsigned int*);
extern void (*glBindVertexArray)(unsigned int);
extern void (*glGenBuffers)(int, unsigned int*);
extern void (*glBindBuffer)(unsigned int, unsigned int);
extern void (*glBufferData)(unsigned int, ptrdiff_t, const void*, unsigned int);
extern void (*glBufferSubData)(unsigned int, ptrdiff_t, ptrdiff_t, const void*);
extern void (*glEnableVertexAttribArray)(unsigned int);
extern void (*glVertexAttribPointer)(unsigned int, int, unsigned int, unsigned char, int, const void*);
extern void (*glDrawElements)(unsigned int, int, unsigned int, const void*);
extern void (*glDeleteVertexArrays)(int, const unsigned int*);
extern void (*glDeleteBuffers)(int, const unsigned int*);
extern void (*glViewport)(int, int, int, int);
extern void (*glClearColor)(float, float, float, float);
extern void (*glEnable)(GLenum);
extern void (*glDisable)(GLenum);
extern void (*glCullFace)(GLenum);
extern void (*glClear)(unsigned int);
extern void (*glUseProgram)(unsigned int);
extern void (*glUniformMatrix4fv)(int, int, unsigned char, const float*);
extern void (*glUniform3f)(int, float, float, float);
extern void (*glUniform1f)(int, float);
extern unsigned int (*glCreateShader)(GLenum);
extern void (*glShaderSource)(unsigned int, int, const char* const*, const int*);
extern void (*glCompileShader)(unsigned int);
extern void (*glGetShaderiv)(unsigned int, GLenum, int*);
extern void (*glGetShaderInfoLog)(unsigned int, int, int*, char*);
extern void (*glDeleteShader)(unsigned int);
extern unsigned int (*glCreateProgram)(void);
extern void (*glAttachShader)(unsigned int, unsigned int);
extern void (*glLinkProgram)(unsigned int);
extern void (*glGetProgramiv)(unsigned int, GLenum, int*);
extern void (*glGetProgramInfoLog)(unsigned int, int, int*, char*);
extern void (*glDeleteProgram)(unsigned int);
extern int (*glGetUniformLocation)(unsigned int, const char*);

/* Loader function */
int gladLoadGLLoader(GLADloadfunc load);

#ifdef __cplusplus
}
#endif

#endif /* GLAD_GL_H_ */
