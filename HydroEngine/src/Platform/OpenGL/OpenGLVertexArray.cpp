#include "OpenGLVertexArray.h"
#include "OpenGLVertexBufferLayout.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"

namespace Hydro
{
	OpenGLVerterArray::OpenGLVerterArray()
	{
		GLCall(glGenVertexArrays(1, &m_RendererID));
	}

	OpenGLVerterArray::~OpenGLVerterArray()
	{
		GLCall(glDeleteVertexArrays(1, &m_RendererID));
	}

	void OpenGLVerterArray::Bind() const
	{
		GLCall(glBindVertexArray(m_RendererID));
	}

	void OpenGLVerterArray::UnBind() const
	{
		GLCall(glBindVertexArray(0));
	}

	void OpenGLVerterArray::AddBuffer(const OpenGLVertexBuffer & vb, const OpenGLVertexbufferLayout & layout)
	{
		Bind();
		vb.Bind();
		const auto& elements = layout.GetElements();
		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
			offset += element.count * OpenGLVertexBufferElement::GetSizeOfType(element.type);
		}
	}
}

