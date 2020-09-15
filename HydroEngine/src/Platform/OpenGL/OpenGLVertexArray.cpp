#include "OpenGLVertexArray.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"
#include "../../Renderer/buffer/BufferLayout.h"
namespace Hydro
{

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Hydro::ShaderDataType::Float:    return GL_FLOAT;
		case Hydro::ShaderDataType::Float2:   return GL_FLOAT;
		case Hydro::ShaderDataType::Float3:   return GL_FLOAT;
		case Hydro::ShaderDataType::Float4:   return GL_FLOAT;
		case Hydro::ShaderDataType::Mat3:     return GL_FLOAT;
		case Hydro::ShaderDataType::Mat4:     return GL_FLOAT;
		case Hydro::ShaderDataType::Int:      return GL_INT;
		case Hydro::ShaderDataType::Int2:     return GL_INT;
		case Hydro::ShaderDataType::Int3:     return GL_INT;
		case Hydro::ShaderDataType::Int4:     return GL_INT;
		case Hydro::ShaderDataType::Bool:     return GL_BOOL;
		}

		return 0;
	}


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

	void OpenGLVerterArray::AddBuffer(const VertexBuffer *vb, const BufferLayout *layout)
	{
		Bind();
		vb->Bind();
		const auto& elements = layout->GetElements();
		unsigned int offset = 0;
		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];

			auto type = ShaderDataTypeToOpenGLBaseType(element.Type);

			GLCall(glEnableVertexAttribArray(i));
			GLCall(glVertexAttribPointer(i, element.GetComponentCount(), type, element.Normalized, layout->GetStride(), (const void*)(intptr_t)element.Offset));
		}
	}
}

