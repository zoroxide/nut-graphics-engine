#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Model.h"
#include "../external/glfw/include/GLFW/glfw3.h"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void loadModel(const std::string& modelPath);
    void renderFrame();
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
    Shader* shader;
    Model* model;
    void initWindow();
};

#endif
