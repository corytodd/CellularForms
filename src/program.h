#define GL_SILENCE_DEPRECATION

#if defined(WIN32)
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>
#include <string>

class Program {
public:
    Program(std::string vsrc, std::string fsrc);
    void Use() const;
    GLint GetUniformLocation(std::string name) const;
    GLint GetAttribLocation(std::string name) const;
private:
    GLuint m_Program;
};
