#ifndef ENGINE_H
#define ENGINE_H

#include "Renderer.h"

class Engine {
public:
    Engine();
    ~Engine();
    void render(const std::string& modelPath);
    void engine_draw(Shader shader);
    void engine_load(const std::string& modelPath);

private:
    Shader *shader = nullptr;
    Model *model = nullptr;
    GLFWwindow* window;
    Renderer* renderer;
    void init();
};

#endif
