#include "GameObject.h"
#include "../Hydro.h"
namespace Hydro
{
	GameObject::GameObject()
	{
		transform = hnew Transform();
	}

	GameObject::~GameObject()
	{
		hdel transform;
	}
}

