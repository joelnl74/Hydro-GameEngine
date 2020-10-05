#include "Renderer2D.h"
#include "buffer/VertexArray.h"
#include "buffer/VertexBuffer.h"
#include "buffer/BufferLayout.h"
#include "buffer/IndexBuffer.h"
#include "Shader.h"

namespace Hydro 
{
	struct VertexData
	{
		glm::vec2 position;
		glm::vec2 uv;
	};

	struct Renderer2DData
	{
		static const uint32_t MaxQuads = 20000;
		static const uint32_t MaxVertices = MaxQuads * 4;
		static const uint32_t MaxIndices = MaxQuads * 6;

		VertexArray *QuadVertexArray;
		VertexBuffer *QuadVertexBuffer;
		Shader *TextureShader;

		uint32_t QuadIndexCount = 0;
		VertexData* QuadVertexBufferBase = nullptr;
		VertexData* QuadVertexBufferPtr = nullptr;

		uint32_t TextureSlotIndex = 1;

		glm::vec4 QuadVertexPositions[4];

		glm::mat4 CameraViewProj;
	};

	static Renderer2DData s_Data;


	void Renderer2d::StartUp()
	{
		BufferLayout* layout = new BufferLayout({
			{ ShaderDataType::Float3, "position" },
			{ ShaderDataType::Float3, "texCoord" },
		});

		s_Data.QuadVertexBuffer = VertexBuffer::Create(s_Data.MaxVertices * sizeof(VertexData));
		s_Data.QuadVertexArray = VertexArray::Create();

		s_Data.QuadVertexBufferBase = new VertexData[s_Data.MaxVertices];

		uint32_t* quadIndices = new uint32_t[s_Data.MaxIndices];
		uint32_t offset = 0;

		for (uint32_t i = 0; i < s_Data.MaxIndices; i += 6)
		{
			quadIndices[i + 0] = offset + 0;
			quadIndices[i + 1] = offset + 1;
			quadIndices[i + 2] = offset + 2;

			quadIndices[i + 3] = offset + 2;
			quadIndices[i + 4] = offset + 3;
			quadIndices[i + 5] = offset + 0;

			offset += 4;
		}

		IndexBuffer *quadIB = IndexBuffer::Create(quadIndices, s_Data.MaxIndices);
		delete[] quadIndices;

		s_Data.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
		s_Data.QuadVertexPositions[1] = { 0.5f, -0.5f, 0.0f, 1.0f };
		s_Data.QuadVertexPositions[2] = { 0.5f,  0.5f, 0.0f, 1.0f };
		s_Data.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };
	}

	void  Renderer2d::ShutDown()
	{

	}

	void  Renderer2d::BeginScene(glm::mat4x4& viewProjectionMatirx)
	{
		s_Data.TextureShader->Bind();
		s_Data.TextureShader->SetMatrix4("u_ViewProjection", viewProjectionMatirx);

		s_Data.QuadIndexCount = 0;
		s_Data.QuadVertexBufferPtr = s_Data.QuadVertexBufferBase;

		s_Data.TextureSlotIndex = 1;
	}

	void Renderer2d::EndScene()
	{
		uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.QuadVertexBufferPtr - (uint8_t*)s_Data.QuadVertexBufferBase);
		s_Data.QuadVertexBuffer->SetData(s_Data.QuadVertexBufferBase, dataSize);
	}

	void Renderer2d::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{

	}
}
