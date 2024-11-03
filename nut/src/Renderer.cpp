#include "../external/glad/include/glad/glad.h"
#include "Renderer.h"
#include <iostream>

Renderer::Renderer() {
    initWindow();
    shader = new Shader("resources/shaders/vertex_shader.glsl", "resources/shaders/fragment_shader.glsl");
}

Renderer::~Renderer() {
    delete shader;
    delete model;
    glfwDestroyWindow(window);
}

void Renderer::initWindow() {
    window = glfwCreateWindow(800, 600, "Nut Enigne", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
}

void Renderer::loadModel(const std::string& modelPath) {
    model = new Model(modelPath);
}

void Renderer::renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader->use();
    model->draw(*shader);  // Render the model with the shader
    glfwSwapBuffers(window);
}

GLFWwindow* Renderer::getWindow() const {
    return window;
}
