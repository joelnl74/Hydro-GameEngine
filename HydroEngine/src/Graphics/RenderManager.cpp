#include "RenderManager.h"
#include "../Hydro.h"
#include "OpenGLDebugger/OpenglErrorHandler.h"

RenderManager *RenderManager::m_instance = 0;

void RenderManager::StartUp()
{
	if (m_instance == 0)
	{
		m_instance = hnew RenderManager();
		m_instance->shader = hnew Shader("Resources/shaders/Basic.shader");
	    m_instance->_camera = hnew Camera(800, 600, CameraMode::orthographic);
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
	hdel m_instance->shader;
	hdel m_instance;
}