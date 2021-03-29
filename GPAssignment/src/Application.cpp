#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

void init() {
	// Initialize GLFW Windows
	glfwInit();

	// Specifying that the minimum OpenGL vesion is 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Use the OpenGL Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// macOS needs below code to use OpenGL
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

// A callback function that fires when window get resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// process keyboard input 
void processInput(GLFWwindow* window) {
	// if Esc key is pressed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		// close the window
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		// fly up
		std::cout << "Fly Up" << std::endl;

	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		// fly left
		std::cout << "Fly Left" << std::endl;

	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		// fly down
		std::cout << "Fly Down" << std::endl;

	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		// fly right
		std::cout << "Fly Right" << std::endl;

	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		// accelerate
		std::cout << "Accelerate" << std::endl;

	}
}

int main(void) {
	// Initialize GLFW
	init();

	// Create a GLFW Window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set the current context to this window object
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1); // Synchronize the animation

	// Initialize GLEW
	if (glewInit() != GLEW_OK) std::cout << "GLEW Init has error" << std::endl;

	// Printing the current OpenGL Version
	std::cout << glGetString(GL_VERSION) << std::endl;

	// x, y coordinates of the vertices
	float positions[] = {
		-0.5f, -0.5f, // 0
		 0.5f, -0.5f, // 1
		 0.5f,  0.5f, // 2
		-0.5f,  0.5f, // 3
	};

	unsigned int indices[] = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
	};

	VertexArray va; // Create a vertex array
	VertexBuffer vb(positions, 4 * 2 * sizeof(float)); // Create a vertex buffer

	VertexBufferLayout layout; // Create a layout for the vertex buffer
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indices, 6); // Create an index buffer

	Shader shader("res/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f); // Applying uniform color
	
	va.Unbind();
	shader.Unbind();
	vb.Unbind();
	ib.Unbind();

	Renderer renderer;

	float r = 0.0f;
	float increment = 0.5f;

	// Setting the OpenGL Viewport
	glViewport(0, 0, 800, 600);

	// Calls the function everytime when window get resized
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// While the window should not be closed
	while (!glfwWindowShouldClose(window)) {
		// Process user input
		processInput(window);

		// Render things here
		renderer.Clear();

		shader.Bind();
		shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

		renderer.Draw(va, ib, shader);

		// Changing color value
		if (r > 1.0f) increment = -0.05f;
		else if (r < 0.0f) increment = 0.05f;

		r += increment;

		// Listen to input events (eg. keyboard input or mouse events)
		glfwPollEvents();

		// Swap the color buffer (a large 2D buffer that contains color values
		// for each pixel in GLFW window)
		glfwSwapBuffers(window);
	}

	// When we break out of the render loop
	// properly clean GLFW resources that was allocated
	glfwTerminate();

	return 0;
}