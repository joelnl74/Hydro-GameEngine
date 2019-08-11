#pragma once
#include "../Component.h"
#include "../../Hydro.h"
#include "../../Utilities/Input.h"

namespace Hydro
{
	class PlayerTest : public Component
	{
		void Start()
		{

		}
		void Update()
		{
			if (Input::s_Instance->IsKeyPressed(HY_KEY_W))
			{
				transform->position.y += 1;
			}
			if (Input::s_Instance->IsKeyPressed(HY_KEY_S))
			{
				transform->position.y -= 1;
			}
			if (Input::s_Instance->IsKeyPressed(HY_KEY_A))
			{
				transform->position.x -= 1;
			}
			if (Input::s_Instance->IsKeyPressed(HY_KEY_D))
			{
				transform->position.x += 1;
			}

			//LOG_INFO("Position x: " + (char)transform->position.x + " Position y: " + (char*)transform->position.y);
		}
	};
}

