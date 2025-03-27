#include "Renderer.h"

Renderer::Renderer() {
    shader = new Shader("../resources/shaders/vertex_shader.glsl", "../resources/shaders/fragment_shader.glsl");
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
