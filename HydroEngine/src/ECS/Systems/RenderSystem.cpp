#include "RenderSystem.h"
#include "../ECS_Engine.h"
#include "../Components/Sprite.h"

RenderSystem::RenderSystem()
{
	Init();

}


RenderSystem::~RenderSystem()
{
	hdel batch;
}

bool RenderSystem::Init()
{
	batch = hnew spriteBatch();

	return true;
}

void RenderSystem::Update()
{
	if (update == true)
	 {
		//update = false;
		batch->Begin();
		for (Sprite* sprite : ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Sprite>())
		{
			batch->Submit(sprite);
		}
		batch->End();
	 }
	batch->Flush();
}
