#include <iostream>
//#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int, char**){
    std::cout << "Hello, from Breakout!" << std::endl;;

    if(!glfwInit()) {
        std::cout << "OpenGL could not start." << std::endl;
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(.25f, .5f, .75f, 1.f);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
