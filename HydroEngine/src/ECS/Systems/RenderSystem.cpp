#include "RenderSystem.h"
#include "../ECS_Engine.h"
#include "../Components/Sprite.h"

RenderSystem::RenderSystem()
{
	Init();

}


RenderSystem::~RenderSystem()
{
	hdel layer;
}

bool RenderSystem::Init()
{
	layer = hnew Layer(false);
	return true;
}

void RenderSystem::Update()
{
	std::vector<Component*> &sprites = ECS_Engine::GetInstance().m_ComponentManager->GetComponentsOfType<Sprite>();

	for (Component *component : sprites)
	{
		Sprite &sprite = *dynamic_cast<Sprite*>(component);
		layer->SubmitSprite(sprite);

		layer->DrawBatch();
	}

}
