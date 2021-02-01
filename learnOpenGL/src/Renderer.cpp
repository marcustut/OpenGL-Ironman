#include "Renderer.h"

#include <iostream>

// Clear errors from OpenGL
void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

// Log the error to console
bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << "): " << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Clear() const {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

// Draw function to draw in a render loop
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr)); // Draw using the index buffer
}
