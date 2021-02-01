#include "VertexArray.h"

#include "VertexBufferLayout.h"
#include "Renderer.h"

VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &m_RendererID)); // Generate a vertex array
}

VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_RendererID)); // Delete the vertex array
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
	Bind(); // bind current vertex array to OpenGL
	vb.Bind(); // bind the vertex buffer to OpenGL
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	// for each element in the layout
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i)); // Enable the vertex attribute
		GLCall(glVertexAttribPointer(i, element.count, element.type,
			element.normalized, layout.GetStride(), (const void*)offset)); // Define the vertex attribute
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type); // increment the offset
	}
}

void VertexArray::Bind() const {
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const {
	GLCall(glBindVertexArray(0));
}
