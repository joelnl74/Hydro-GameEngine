#include "GameObject.h"
#include "../Hydro.h"
namespace Hydro
{
	GameObject::GameObject()
	{
		transform = new Transform();
	}

	GameObject::~GameObject()
	{
		delete transform;
	}
}

