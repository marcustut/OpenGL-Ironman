#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FraagmentSource;
};

// Parse the shader source code from a file
static ShaderProgramSource ParseShader(const std::string& filepath) {
	// Read the file
	std::ifstream stream(filepath);
	
	// An enum for differentiating types of shader
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2]; // an array of 2 stringstream for input
	ShaderType type = ShaderType::NONE;

	// loop through each line in the stream
	while (getline(stream, line)) {
		// if we find '#shader'
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) 
				// if find 'vertex', set the type to vertex
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos) 
				// if find 'fragment', set the type to fragment
				type = ShaderType::FRAGMENT;
		}
		// else just input the line into its corresponding stringstream
		else {
			ss[(int)type] << line << '\n';
		}
	}

	// return a struct of both shaders
	return { ss[0].str(), ss[1].str() };
}

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
}

// to compile a shader
static unsigned int CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type); // create a vertex shader
	const char* src = source.c_str(); // get the first pointer to the source code string

	glShaderSource(id, 1, &src, nullptr); // replace the source code currently in the shader
	glCompileShader(id); // compile the source code currently in the shader

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result); // query OpenGL to check errors
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length); // get the error message
		char* message = (char*) _malloca(length * sizeof(char)); // allocate memory dynamically on the stack
		glGetShaderInfoLog(id, length, &length, message); // write the message

		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id); // delete the shader
		return 0;
	}

	return id;
}

// to create a shader 
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram(); // create a program

	// compile the shader source code
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	// attach the compiled shader to the program
	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program); // link the program object
	glValidateProgram(program); // validate the program object

	// delete the shader object since they are already linked
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
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

	unsigned int buffer;
	glGenBuffers(1, &buffer); // Generating a buffer in OpenGL
	glBindBuffer(GL_ARRAY_BUFFER, buffer); // Bind OpenGL to the buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW); // Writing data to the buffer

	glEnableVertexAttribArray(0); // Enable the vertex attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); // Define the vertex attribute

	unsigned int ibo; // ibo (index buffer object)
	glGenBuffers(1, &ibo); 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo); 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW); 

	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader"); // parse the shader from a file
	unsigned int shader = CreateShader(source.VertexSource, source.FraagmentSource); // create shader from source code
	glUseProgram(shader); // apply the shader

	// Setting the OpenGL Viewport
	glViewport(0, 0, 800, 600);

	// Calls the function everytime when window get resized
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// While the window should not be closed
	while (!glfwWindowShouldClose(window)) {
		// Process user input
		processInput(window);

		// Render things here
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // Draw using the index buffer

		// Listen to input events (eg. keyboard input or mouse events)
		glfwPollEvents();

		// Swap the color buffer (a large 2D buffer that contains color values
		// for each pixel in GLFW window)
		glfwSwapBuffers(window);
	}

	glDeleteProgram(shader);

	// When we break out of the render loop
	// properly clean GLFW resources that was allocated
	glfwTerminate();

	return 0;
}