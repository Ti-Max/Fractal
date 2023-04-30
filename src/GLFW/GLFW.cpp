#include "GLFW.h"

GLFW::GLFW()
{
    if (glfwInit())
    {
        std::cout << "GLFW is conected" << std::endl;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }
    else {
        std::cout << "Failed to conect GLFW" << std::endl;
    }
}

GLFW::~GLFW()
{
    glfwTerminate();
}
