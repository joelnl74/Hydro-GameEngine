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
			m_instance->shader = new Shader("Resources/shaders/Basic.shader");
			m_instance->_camera = new Camera(800, 600, CameraMode::orthographic);
			m_instance->_spriteBatch = new spriteBatch();
			//TODO: END
			m_instance->shader->Bind();

			//TODO: Remove
			GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
			GLCall(glEnable(GL_BLEND));

			m_instance->shader->SetMatrix4("orthographicModel", m_instance->_camera->returnProjection());
			m_instance->shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));
			m_instance->_camera->centerCamera(0, 0);
			m_instance->shader->SetMatrix4("orthographicModel", m_instance->_camera->returnProjection());
		}
	}
	void RenderManager::ShutDown()
	{
		for (auto batch : m_SpriteBatches)
		{
			delete batch;
		}

		m_SpriteBatches.clear();

		delete m_instance->shader;
		delete m_instance;
	}
	void RenderManager::Draw()
	{
		// Draw all 3D meshes.

		// Draw particles???

		// Draw all sprite batches.
		for (int i = 0; i < m_SpriteBatches.size(); i++)
		{
			if (m_SpriteBatches[i]->staticBatch)
			{
				m_SpriteBatches[i]->Begin();
			}
			m_SpriteBatches[i]->Flush();
			m_SpriteBatches[i]->End();
		}
	}

}
