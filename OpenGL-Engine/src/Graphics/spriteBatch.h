#pragma once
#include "Sprite.h"

#define MAX_SPRITES			 20025
#define VERTEX_SIZE			 sizeof(VertexData)
#define SPRITE_SIZE			 VERTEX_SIZE * 4
#define BUFFER_SIZE			 SPRITE_SIZE * MAX_SPRITES
#define INDEX_BUFFER_SIZE	 MAX_SPRITES * 6


class spriteBatch
{
public:
	spriteBatch();
	~spriteBatch();

	void init();

	void begin();
	void end();

	void submit(Sprite *sprite);
	void flush();

private:
	unsigned int vbo;
	unsigned int vao;
	VertexData *buffer;
	IndexBuffer *indexbuffer;
	unsigned int indexcount;
};

