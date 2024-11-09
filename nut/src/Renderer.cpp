#include "Renderer.h"
#include <iostream>

Renderer::Renderer() {
    // Initialize the shader, but don't create a window here
    shader = new Shader("resources/shaders/vertex_shader.glsl", "resources/shaders/fragment_shader.glsl");
}

Renderer::~Renderer() {
    delete shader;
    if (model) delete model;
}

void Renderer::loadModel(const std::string& modelPath) {
    model = new Model(modelPath);
}

void Renderer::renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader->use();
    if (model) {
        model->draw(*shader);
    }
}
