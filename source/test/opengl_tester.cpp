#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

enum Scenario { GLFW_INIT, GLAD_INIT, CREATE_WINDOW };

using namespace std;

constexpr int MIN_ARGUMENT_NUMBER = 2;
constexpr int NORMAL_ARGUMENT_NUMBER = 2;

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

int glfw_init() {
    int res = GLFW_FALSE;
    res = glfwInit();
    glfwTerminate();
    if (res == GLFW_TRUE) {
        return 0;
    } else {
        return -1;
    }
}

int glad_init() {
    glfwInit();
    if (gladLoadGL() == 0) {
        return -1;
    }
    return 0;
}

int create_window(const int width = 640, const int height = 480,
                  const int timeout = 2000) {
    auto gl_ok = glfw_init();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow *window =
        glfwCreateWindow(width, height, "Test window", NULL, NULL);
    if (!window) {
        cout << "Window or OpenGL context creation failed" << endl;
        return -1;
    }
    glfwDestroyWindow(window);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < MIN_ARGUMENT_NUMBER) {
        cout << "Missing Scenario argument" << endl;
        return -1;
    }
    auto scenar = static_cast<Scenario>(stoi(argv[1]));
    switch (scenar) {
    case GLFW_INIT:
        cout << "glfw_init" << endl;
        return glfw_init();
        break;

    case GLAD_INIT:
        cout << "glad_init" << endl;
        return glad_init();
        break;

    case CREATE_WINDOW:
        cout << "create_window" << endl;
        return create_window();
        break;

    default:
        cout << "Unplanned Scenario, exit" << endl;
        return -1;
        break;
    }
    return 0; // technically unreachable
}
