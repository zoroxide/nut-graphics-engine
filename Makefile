CXX = g++
CXXFLAGS = -std=c++17 -I./external/glad/include -I./external/glm -I./external/glfw/include -I./external/tinyobjloader

SOURCES = main.cpp src/Shader.cpp src/Model.cpp src/Renderer.cpp src/Engine.cpp \
          external/tinyobjloader/tiny_obj_loader.cc external/glad/src/glad.c

LDFLAGS = -L./external/glfw/build/src -lglfw -lGL -lGLU -lX11 -lpthread -lm -ldl

TARGET = build/app

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf build
