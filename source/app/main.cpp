#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

int main(int, char **) {
    std::cout << "Breakout starting..." << std::endl;
    ;

    if (!glfwInit()) {
        std::cout << "OpenGL could not start." << std::endl;
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    int glad_version = gladLoadGL();
    if (glad_version == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl
                  << "glad loading gave: " << glad_version << std::endl;
        return -1;
    }

    glClearColor(.25f, .5f, .75f, 1.f);
    while (!glfwWindowShouldClose(window)) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
