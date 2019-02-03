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
		std::vector<Component*> &sprites = ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Sprite>();
			for (Component *component : sprites)
			{
				Sprite *sprite = dynamic_cast<Sprite*>(component);
				m_sprites.push_back(sprite);
			}
		update = false;
		batch->Begin();
		for (Sprite* sprite : m_sprites)
		{
			batch->Submit(sprite);
		}
		batch->End();
	}
	batch->Flush();


}
