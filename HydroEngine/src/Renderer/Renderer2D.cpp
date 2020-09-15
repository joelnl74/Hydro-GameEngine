#include "Renderer2D.h"
#include "buffer/VertexArray.h"
#include "buffer/VertexBuffer.h"
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
		// s_Data.QuadVertexArray = VertexArray::Create();
	}

	void  Renderer2d::ShutDown()
	{

	}

	void  Renderer2d::BeginScene(const glm::mat4x4& viewProjectionMatirx)
	{

	}

	void Renderer2d::EndScene()
	{

	}

	void Renderer2d::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{

	}
}
