#include "pointLight.h"

pointLight::pointLight()
{
	intensity = 0.5f;
	colors.r = 1;
	colors.g = 1;
	colors.b = 1;
	colors.a = intensity;
}


pointLight::~pointLight()
{
}
