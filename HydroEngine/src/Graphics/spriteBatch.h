#pragma once
#include "../ECS/Components/Sprite.h"
#include "buffer/VertexBuffer.h"
#include "buffer/VertexBufferLayout.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "../Hydro.h"

#define MAX_SPRITES			 21000
#define VERTEX_SIZE			 sizeof(VertexData)
#define SPRITE_SIZE			 VERTEX_SIZE * 4
#define BUFFER_SIZE			 SPRITE_SIZE * MAX_SPRITES
#define INDEX_BUFFER_SIZE	 MAX_SPRITES * 6


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
	void Submit(Sprite *sprite);
	//Draw the current frame
	void Flush();

private:
	unsigned int vbo;
	unsigned int vao;
	VertexData *buffer;
	IndexBuffer *indexbuffer;
	unsigned int indexcount;
};

