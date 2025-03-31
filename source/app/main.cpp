#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

unsigned int make_module(const std::string &file_path,
                         const unsigned int module_type) {
    std::ifstream file;
    std::stringstream buffer_lines;
    std::string line;

    file.open(file_path);
    while (std::getline(file, line)) {
        buffer_lines << line << "\n";
    }
    std::string shader_source = buffer_lines.str();
    const char *shader_src = shader_source.c_str();
    buffer_lines.str("");
    file.close();

    unsigned int shader_module = glCreateShader(module_type);
    glShaderSource(shader_module, 1, &shader_src, NULL);
    glCompileShader(shader_module);

    GLint success;
    glGetShaderiv(shader_module, GL_COMPILE_STATUS, &success);
    if (!success) {
        char error_log[1024];
        glGetShaderInfoLog(shader_module, 1024, NULL, error_log);
        std::cout << "Error while shader compilation: " << error_log
                  << std::endl;
    }
    return shader_module;
}

unsigned int make_shader(const std::string &vertex_file_path,
                         const std::string &fragment_file_path) {
    std::vector<unsigned int> modules;
    modules.push_back(make_module(vertex_file_path, GL_VERTEX_SHADER));
    modules.push_back(make_module(fragment_file_path, GL_FRAGMENT_SHADER));

    unsigned int shader = glCreateProgram();

    for (auto shader_module : modules) {
        glAttachShader(shader, shader_module);
    }
    glLinkProgram(shader);

    GLint success;
    glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char error_log[1024];
        glGetProgramInfoLog(shader, 1024, NULL, error_log);
        std::cout << "Error while shader compilation: " << error_log
                  << std::endl;
    }

    for (auto shader_module : modules) {
        glDeleteShader(shader_module);
    }

    return shader;
}

int main(int, char **) {
    std::cout << "Breakout starting..." << std::endl;

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
    GLuint shader =
        make_shader("./shaders/vertex.txt", "./shaders/fragment.txt");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        glfwSwapBuffers(window);
    }

    glDeleteProgram(shader);
    glfwTerminate();
    return 0;
}
