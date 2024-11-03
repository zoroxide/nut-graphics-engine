#ifndef MODEL_H
#define MODEL_H

#include "Shader.h"
#include <string>
#include <vector>

class Model {
public:
    Model(const std::string& path);
    void draw(Shader& shader);
    void loadModel(const std::string& path);

private:
    std::vector<float> vertices;
    unsigned int VAO, VBO;
};

#endif
