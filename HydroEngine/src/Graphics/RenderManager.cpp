#include "RenderManager.h"
#include "../Hydro.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"

namespace Hydro
{
	RenderManager *RenderManager::m_instance = 0;

	void RenderManager::StartUp()
	{
		if (m_instance == 0)
		{
			m_instance = new RenderManager();
			m_instance->m_shader = new OpenGLShader("Resources/shaders/Basic.shader");
			m_instance->m_camera = new Camera(800, 600, CameraMode::orthographic);
			m_instance->m_spriteBatch = new spriteBatch();
			m_instance->m_spriteBatch->Init();
			//TODO: END
			m_instance->m_shader->Bind();

			//TODO: Remove
			GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
			GLCall(glEnable(GL_BLEND));

			m_instance->m_shader->SetMatrix4("orthographicModel", m_instance->m_camera->returnProjection());
			m_instance->m_shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
			m_instance->m_camera->centerCamera(0, 0);
			m_instance->m_shader->SetMatrix4("orthographicModel", m_instance->m_camera->returnProjection());
		}
	}
	void RenderManager::ShutDown()
	{
		delete m_instance->m_shader;
		delete m_instance->m_camera;
		delete m_instance;
	}
	void RenderManager::Draw()
	{
		// Draw all 3D meshes.

		// Draw particles???

		// Draw all sprite batches.
	}
}
