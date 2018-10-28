#include "spriteBatch.h"

spriteBatch::spriteBatch()
{
	Init();
}
spriteBatch::~spriteBatch()
{
	glDeleteBuffers(1, &vbo);
	hdel indexbuffer;
	hdel buffer;
}
//Create Buffers
void spriteBatch::Init()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindVertexArray(vao);

	glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//position coordinates
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const void*)0);
	//texture coordinates
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const void*)(offsetof(VertexData, VertexData::uv)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	unsigned int indices[INDEX_BUFFER_SIZE];

	unsigned int offset = 0;
	for (unsigned int i = 0; i < INDEX_BUFFER_SIZE; i += 6)
	{
		indices[  i  ] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;

		offset += 4;

	}
	indexbuffer = hnew IndexBuffer(indices, INDEX_BUFFER_SIZE);

	glBindVertexArray(0);
}
//Creating a mapbuffer to store all the vbo data
void spriteBatch::Begin()
{
	indexcount = 0;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}
//unmap the buffer
void spriteBatch::End()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
//Settingup sprite data for the buffers
void spriteBatch::Submit(Sprite *sprite)
{
	//TODO set uv offset based on image width height
	glm::vec2 spritePosition =  sprite->getPosition();
	glm::vec2 spriteScale =     sprite->getScale();
	glm::vec2 uv =				sprite->getUV();

	//TODO set texture offset based on object object size
	buffer->position = spritePosition;
	buffer->uv =	   glm::vec2(uv.x + 0.00125f, uv.y + 0.25f - 0.00125f);
	buffer++;

	buffer->position = glm::vec2(spritePosition.x, spritePosition.y + spriteScale.y);
	buffer->uv =	   glm::vec2(uv.x + 0.00125f, uv.y + 0.00125f);
	buffer++;

	buffer->position = glm::vec2(spritePosition.x + spriteScale.x, spritePosition.y + spriteScale.y);
	buffer->uv =	   glm::vec2(uv.x + 0.25f - 0.00125f, uv.y + 0.00125f);
	buffer++;

	buffer->position = glm::vec2(spritePosition.x + spriteScale.x, spritePosition.y);
	buffer->uv =       glm::vec2(uv.x + 0.25f - 0.00125f, uv.y + 0.25f - 0.00125f);
	buffer++;

	indexcount += 6;
}
//bind draw unbind
void spriteBatch::Flush()
{
	//only flush if something has changed in the buffer
	glBindVertexArray(vao);
	indexbuffer->Bind();

	glDrawElements(GL_TRIANGLES, indexcount, GL_UNSIGNED_INT, NULL);

	glBindVertexArray(0);
	indexbuffer->Unbind();
}