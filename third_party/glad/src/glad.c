/* glad implementation - minimal loader for Windows/MinGW */
#include <glad/gl.h>

/* Define function pointers */
void (*glGenVertexArrays)(int, unsigned int*) = NULL;
void (*glBindVertexArray)(unsigned int) = NULL;
void (*glGenBuffers)(int, unsigned int*) = NULL;
void (*glBindBuffer)(unsigned int, unsigned int) = NULL;
void (*glBufferData)(unsigned int, ptrdiff_t, const void*, unsigned int) = NULL;
void (*glBufferSubData)(unsigned int, ptrdiff_t, ptrdiff_t, const void*) = NULL;
void (*glEnableVertexAttribArray)(unsigned int) = NULL;
void (*glVertexAttribPointer)(unsigned int, int, unsigned int, unsigned char, int, const void*) = NULL;
void (*glDrawElements)(unsigned int, int, unsigned int, const void*) = NULL;
void (*glDeleteVertexArrays)(int, const unsigned int*) = NULL;
void (*glDeleteBuffers)(int, const unsigned int*) = NULL;
void (*glViewport)(int, int, int, int) = NULL;
void (*glClearColor)(float, float, float, float) = NULL;
void (*glEnable)(GLenum) = NULL;
void (*glDisable)(GLenum) = NULL;
void (*glCullFace)(GLenum) = NULL;
void (*glClear)(unsigned int) = NULL;
void (*glUseProgram)(unsigned int) = NULL;
void (*glUniformMatrix4fv)(int, int, unsigned char, const float*) = NULL;
void (*glUniform3f)(int, float, float, float) = NULL;
void (*glUniform1f)(int, float) = NULL;
unsigned int (*glCreateShader)(GLenum) = NULL;
void (*glShaderSource)(unsigned int, int, const char* const*, const int*) = NULL;
void (*glCompileShader)(unsigned int) = NULL;
void (*glGetShaderiv)(unsigned int, GLenum, int*) = NULL;
void (*glGetShaderInfoLog)(unsigned int, int, int*, char*) = NULL;
void (*glDeleteShader)(unsigned int) = NULL;
unsigned int (*glCreateProgram)(void) = NULL;
void (*glAttachShader)(unsigned int, unsigned int) = NULL;
void (*glLinkProgram)(unsigned int) = NULL;
void (*glGetProgramiv)(unsigned int, GLenum, int*) = NULL;
void (*glGetProgramInfoLog)(unsigned int, int, int*, char*) = NULL;
void (*glDeleteProgram)(unsigned int) = NULL;
int (*glGetUniformLocation)(unsigned int, const char*) = NULL;

/* Loader function */
int gladLoadGLLoader(GLADloadfunc load) {
    if (load == NULL) {
        return 0;
    }

    /* Load all function pointers */
    glGenVertexArrays = (void (*)(int, unsigned int*))load("glGenVertexArrays");
    glBindVertexArray = (void (*)(unsigned int))load("glBindVertexArray");
    glGenBuffers = (void (*)(int, unsigned int*))load("glGenBuffers");
    glBindBuffer = (void (*)(unsigned int, unsigned int))load("glBindBuffer");
    glBufferData = (void (*)(unsigned int, ptrdiff_t, const void*, unsigned int))load("glBufferData");
    glBufferSubData = (void (*)(unsigned int, ptrdiff_t, ptrdiff_t, const void*))load("glBufferSubData");
    glEnableVertexAttribArray = (void (*)(unsigned int))load("glEnableVertexAttribArray");
    glVertexAttribPointer = (void (*)(unsigned int, int, unsigned int, unsigned char, int, const void*))load("glVertexAttribPointer");
    glDrawElements = (void (*)(unsigned int, int, unsigned int, const void*))load("glDrawElements");
    glDeleteVertexArrays = (void (*)(int, const unsigned int*))load("glDeleteVertexArrays");
    glDeleteBuffers = (void (*)(int, const unsigned int*))load("glDeleteBuffers");
    glViewport = (void (*)(int, int, int, int))load("glViewport");
    glClearColor = (void (*)(float, float, float, float))load("glClearColor");
    glEnable = (void (*)(GLenum))load("glEnable");
    glDisable = (void (*)(GLenum))load("glDisable");
    glCullFace = (void (*)(GLenum))load("glCullFace");
    glClear = (void (*)(unsigned int))load("glClear");
    glUseProgram = (void (*)(unsigned int))load("glUseProgram");
    glUniformMatrix4fv = (void (*)(int, int, unsigned char, const float*))load("glUniformMatrix4fv");
    glUniform3f = (void (*)(int, float, float, float))load("glUniform3f");
    glUniform1f = (void (*)(int, float))load("glUniform1f");
    glCreateShader = (unsigned int (*)(GLenum))load("glCreateShader");
    glShaderSource = (void (*)(unsigned int, int, const char* const*, const int*))load("glShaderSource");
    glCompileShader = (void (*)(unsigned int))load("glCompileShader");
    glGetShaderiv = (void (*)(unsigned int, GLenum, int*))load("glGetShaderiv");
    glGetShaderInfoLog = (void (*)(unsigned int, int, int*, char*))load("glGetShaderInfoLog");
    glDeleteShader = (void (*)(unsigned int))load("glDeleteShader");
    glCreateProgram = (unsigned int (*)(void))load("glCreateProgram");
    glAttachShader = (void (*)(unsigned int, unsigned int))load("glAttachShader");
    glLinkProgram = (void (*)(unsigned int))load("glLinkProgram");
    glGetProgramiv = (void (*)(unsigned int, GLenum, int*))load("glGetProgramiv");
    glGetProgramInfoLog = (void (*)(unsigned int, int, int*, char*))load("glGetProgramInfoLog");
    glDeleteProgram = (void (*)(unsigned int))load("glDeleteProgram");
    glGetUniformLocation = (int (*)(unsigned int, const char*))load("glGetUniformLocation");

    return 1;
}
