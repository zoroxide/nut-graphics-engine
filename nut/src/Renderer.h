#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Model.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void loadModel(const std::string& modelPath);
    void renderFrame();

private:
    Shader* shader;
    Model* model = nullptr;
};

#endif
