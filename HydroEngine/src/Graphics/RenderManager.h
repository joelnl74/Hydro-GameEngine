#pragma once
#include "Shader.h"
#include "Camera.h"
#include "spriteBatch.h"
#include <vector>

namespace Hydro
{
	//TODO REMOVE THIS CLASS
	class RenderManager
	{
	public:
		Shader *shader;
		Camera *_camera;
		spriteBatch *_spriteBatch;

		// Startup this subsystem of the engine.
		void StartUp();
		// Close this subsystem of the engine.
		void ShutDown();
		// Draw primitives;
		void Draw();

		inline static RenderManager &GetInstance()
		{
			return *m_instance;
		}
	private:
		static RenderManager *m_instance;
		std::vector<spriteBatch*> m_SpriteBatches;
	};
}






