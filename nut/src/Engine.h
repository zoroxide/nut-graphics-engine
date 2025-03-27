#ifndef ENGINE_H
#define ENGINE_H

#include "Camera.h"
#include "Shader.h"
#include "Model.h"
#include <GLFW/glfw3.h>

class Engine {
public:
    Engine();
    ~Engine();
    void render(const std::string& modelPath);

private:
    GLFWwindow* window;
    Camera camera;
    float lastX, lastY;
    bool firstMouse;

    void init();
    void processInput();

    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
};

#endif