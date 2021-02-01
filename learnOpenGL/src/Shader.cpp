#include "Shader.h"

#include "Renderer.h"

Shader::Shader(const std::string& filepath)
	: m_FilePath(filepath), m_RendererID(0) {
	ShaderProgramSource source = ParseShader(filepath); 
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader() {
	GLCall(glDeleteProgram(m_RendererID));
}

// Parse the shader source code from a file
ShaderProgramSource Shader::ParseShader(const std::string& filepath) {
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

// to compile a shader
unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type); // create a vertex shader
	const char* src = source.c_str(); // get the first pointer to the source code string

	glShaderSource(id, 1, &src, nullptr); // replace the source code currently in the shader
	glCompileShader(id); // compile the source code currently in the shader

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result); // query OpenGL to check errors
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length); // get the error message
		char* message = (char*)_malloca(length * sizeof(char)); // allocate memory dynamically on the stack
		glGetShaderInfoLog(id, length, &length, message); // write the message

		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(id); // delete the shader
		return 0;
	}

	return id;
}

// to create a shader
unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram(); // create a program

	// compile the shader source code
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	// attach the compiled shader to the program
	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));

	GLCall(glLinkProgram(program)); // link the program object
	GLCall(glValidateProgram(program)); // validate the program object

	// delete the shader object since they are already linked
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}

void Shader::Bind() const {
	GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const {
	GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

unsigned int Shader::GetUniformLocation(const std::string& name) {
	// Check if the location is already cached
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	GLCall(unsigned int location = glGetUniformLocation(m_RendererID, name.c_str()));

	if (location == -1)
		std::cout << "Warning: unform " << name << " doesn't exist!" << std::endl;

	// Set the location to cache
	m_UniformLocationCache[name] = location;

	return location;
}
