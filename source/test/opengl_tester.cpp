#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

enum Scenario {
    GLFW_INIT,
    GLAD_INIT,
    OPENGL_WINDOW
};

using namespace std;

constexpr int MIN_ARGUMENT_NUMBER = 2;
constexpr int NORMAL_ARGUMENT_NUMBER = 2;

int glfw_init() {
    int res = GLFW_FALSE;
    try {
        res = glfwInit();
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    glfwTerminate();
    if(res == GLFW_TRUE) {
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

int openlg_window(const int width=640, const int height=480, const int timeout = 2000) {
    auto gl_ok = glfw_init();
    auto glad_ok = glad_init();
    if(gl_ok && glad_ok) {
        auto window = glfwCreateWindow(width, height, "Test Window", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        auto time = 0;
        while(time < timeout) {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            time++;
        }
    }
}

int main(int argc, char** argv)  {
    if (argc < MIN_ARGUMENT_NUMBER) {
        cout << "Missing Scenario argument" << endl;
        return -1;
    }
    auto scenar = static_cast<Scenario>(stoi(argv[1]));
    // auto width = stoi(argv[1]);
    // auto height = stoi(argv[2]);
    switch (scenar)
    {
    case GLFW_INIT:
        cout << "glfw_init" << endl;
        return glfw_init();
        break;

    case GLAD_INIT:
        cout << "glad_init" << endl;
        return glad_init();
        break;

    case OPENGL_WINDOW:
        cout << "openlg_window" << endl;
        return openlg_window();
        break;

    default:
        cout << "Unplanned Scenario, exit" << endl;
        return -1;
        break;
    }
    return 0;
}
