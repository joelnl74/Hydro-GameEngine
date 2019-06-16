#pragma once
#include "Shader.h"
#include "Camera.h"
#include "spriteBatch.h"

namespace Hydro
{
	//TODO REMOVE THIS CLASS
	class RenderManager
	{
	public:
		Shader *m_shader;
		Camera *m_camera;
		spriteBatch *m_spriteBatch;

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
	};
}






