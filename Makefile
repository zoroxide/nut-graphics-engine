CXX = g++
CXXFLAGS = -std=c++17 -I./nut/external/glad/include -I./nut/external/glm -I./nut/external/glfw/include -I./nut/external/tinyobjloader

SOURCES = main.cpp nut/src/Shader.cpp nut/src/Model.cpp nut/src/Renderer.cpp nut/src/Engine.cpp \
          nut/src/Camera.cpp nut/external/tinyobjloader/tiny_obj_loader.cc nut/external/glad/src/glad.c

LDFLAGS = -L./nut/external/glfw/build/src -lglfw -lGL -lGLU -lX11 -lpthread -lm -ldl

TARGET = build/app

$(TARGET): $(SOURCES)
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)
	./$(TARGET)

clean:
	rm -rf build
