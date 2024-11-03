#pragma once
#include "../external/glad/include/glad/glad.h"
#include <string>



class Shader {
public:
    GLuint ID;

    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    void setMat4(const std::string& name, const float* value) const;

private:
    std::string readFile(const std::string& filePath);
    GLuint compileShader(GLenum type, const std::string& source);
};
