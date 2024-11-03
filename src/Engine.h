#ifndef ENGINE_H
#define ENGINE_H

#include "Renderer.h"
#include "Shader.h"
#include "Model.h"
#include "../external/glfw/include/GLFW/glfw3.h"

class Engine {
public:
    Engine();
    ~Engine();
    void render(const std::string& modelPath);

private:
    Shader* shader = nullptr;
    Model* model = nullptr; // Start as nullptr
    GLFWwindow* window;
    Renderer* renderer;
    void init();
};

#endif
