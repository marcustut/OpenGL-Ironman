#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

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

int main() {
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

	// Using GLAD to handle GLFW function pointers
	// glfwGetProcAddress gets the correct function for different OSes
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Setting the OpenGL Viewport
	glViewport(0, 0, 800, 600);

	// Calls the function everytime when window get resized
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// While the window should not be closed
	while (!glfwWindowShouldClose(window)) {
		// Swap the color buffer (a large 2D buffer that contains color values
		// for each pixel in GLFW window)
		glfwSwapBuffers(window);

		// Listen to input events (eg. keyboard input or mouse events)
		glfwPollEvents();
	}

	// When we break out of the render loop
	// properly clean GLFW resources that was allocated
	glfwTerminate();

	return 0;
}