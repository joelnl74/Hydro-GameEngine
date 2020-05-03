#pragma once
#include "Transform.h"

namespace Hydro
{
	class Component
	{
	public:
		~Component() {};

		virtual void Start() = 0;
		virtual void Update() = 0;

		unsigned int GameObjectId;
		Transform *transform;

	private:
		bool active = true;
	};
}
