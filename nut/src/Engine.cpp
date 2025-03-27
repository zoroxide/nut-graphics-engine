#include "Engine.h"
#include <iostream>
#include "../external/glm/glm/gtc/type_ptr.hpp"
#include "../external/glad/include/glad/glad.h"

Engine::Engine()
    : camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 45.0f),
      lastX(400), lastY(300), firstMouse(true) {
    init();
}

Engine::~Engine() {
    glfwTerminate();
}

void Engine::init() {
    glEnable(GL_DEPTH_TEST);
    if (!glfwInit()) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "3D Viewer", nullptr, nullptr);
    if (!window) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }

    glEnable(GL_DEPTH_TEST);
}

void Engine::render(const std::string& modelPath) {
    Model model(modelPath);
    Shader shader("../resources/shaders/vertex_shader.glsl", "../resources/shaders/fragment_shader.glsl");

    while (!glfwWindowShouldClose(window)) {
        processInput();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 projection = camera.getProjectionMatrix(800.0f / 600.0f);

        shader.setMat4("model", glm::value_ptr(modelMatrix));
        shader.setMat4("view", glm::value_ptr(view));
        shader.setMat4("projection", glm::value_ptr(projection));

        model.draw(shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Engine::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    Engine* engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    if (engine->firstMouse) {
        engine->lastX = xpos;
        engine->lastY = ypos;
        engine->firstMouse = false;
    }

    float xoffset = xpos - engine->lastX;
    float yoffset = engine->lastY - ypos; // Reversed since y-coordinates go from bottom to top
    engine->lastX = xpos;
    engine->lastY = ypos;

    engine->camera.processMouseMovement(xoffset, yoffset);
}

void Engine::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    Engine* engine = static_cast<Engine*>(glfwGetWindowUserPointer(window));
    engine->camera.processMouseScroll(yoffset);
}