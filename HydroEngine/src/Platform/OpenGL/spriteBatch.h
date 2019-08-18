#pragma once
#include "../../HyEntity/Components/Sprite.h"
#include "OpenGLVertexBuffer.h"
#include "OpenGLVertexBufferLayout.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLVertexArray.h"
#include "OpenGLShader.h"
#include "OpenGLTexture.h"

#include "../../Hydro.h"

#define MAX_SPRITES			 21000
#define VERTEX_SIZE			 sizeof(VertexData)
#define SPRITE_SIZE			 VERTEX_SIZE * 4
#define BUFFER_SIZE			 SPRITE_SIZE * MAX_SPRITES
#define INDEX_BUFFER_SIZE	 MAX_SPRITES * 6

namespace Hydro
{
	class spriteBatch
	{
	public:
		spriteBatch();
		~spriteBatch();

		//Setup this spritebatch
		void Init();

		//Setup all the buffers
		void Begin();
		//Clear all the buffers
		void End();

		//Submit a sprite to the batch to render this frame
		void Submit(const Sprite *sprite);
		//Draw the current frame
		void Flush();
	public:
		bool staticBatch = false;
	private:
		unsigned int vbo;
		unsigned int vao;
		VertexData *buffer;
		IndexBuffer *indexbuffer;
		unsigned int indexcount;
	};
}
