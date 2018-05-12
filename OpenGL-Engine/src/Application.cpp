//#include "../Win32Window.h"
#include "Graphics/Window.h"
#include "Graphics/Layer.h"
#include "Graphics/Camera2D.h"

#include "audio/AudioEngine.h"
#include "EngineUI/EditorUI.h"

const int WIDTH  = 1024;
const int HEIGHT = 768;

int main(void)
{
	double lastTime = glfwGetTime();
	double deltaTime = 1.0 / 30;

	//create a window
	Window window(WIDTH, HEIGHT, "Hydro Engine");
	EditorUI UI(window.getWindow());
	ImGuiIO& io = ImGui::GetIO();

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));

	//Simple 2dcamera class
	Camera2D *camera2d = new Camera2D(720, 480);

	Shader shader = Shader("res/shaders/Basic.shader");
	shader.Bind();

	shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	shader.setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));

	//create a rederer object from which you can call draw calls
	Layer *background = new Layer();

	//create a texture
	Texture texture = Texture("res/textures/Tiles.png");

	int xX = 0;
	int yY = 0;
	//test code for rendering a lot sprites
	for (int i = 0; i < 20024; i++)
	{
		Sprite *m_sprite = new Sprite(32, 32, 32 * xX, 32 * yY );
		m_sprite->setIndex(4, 4);
		m_sprite->setTextureUV(0, 0);
		if (xX == 0 || yY == 0 || yY == 141)
		{
			m_sprite->setTextureUV(1, 0);
		}
		xX++;
		if (xX == 141)
		{
			m_sprite->setTextureUV(1, 0);
			yY++;
			xX = 0;
		}
		background->submitSprite(*m_sprite);
	}
	Sprite *m_player = new Sprite(32, 32, 0, 0);
	m_player->setIndex(4, 4);
	m_player->setTextureUV(1, 1);
	background->submitSprite(*m_player);
	//Create a audioengine object
	//AudioEngine engine;
	//Load a audio file
	//engine.LoadAudioFileFromSystem("res\sounds\sound1.wav");
	//play the loaded audio file
	//engine.PlaySound();

	int playerspeed_x = 32;
	int playerspeed_y = 32;

	texture.bind();
	//Gameloop 
	while (!window.closed())
	{
		double currentTime = glfwGetTime();
		if (currentTime - lastTime >= deltaTime) {

			if (ImGui::IsKeyDown(GLFW_KEY_A) && UI.returnPlay())
			{
				m_player->TransLate(-playerspeed_x * 9.81f * deltaTime, 0, 0);
			}
			if (ImGui::IsKeyDown(GLFW_KEY_D) && UI.returnPlay())
			{
				m_player->TransLate(playerspeed_x* 9.81f * deltaTime, 0, 0);
			}
			if (ImGui::IsKeyDown(GLFW_KEY_W) && UI.returnPlay())
			{
				m_player->TransLate(0, playerspeed_y * 9.81f * deltaTime, 0);
			}
			if (ImGui::IsKeyDown(GLFW_KEY_S) && UI.returnPlay())
			{
				m_player->TransLate(0, -playerspeed_y * 9.81f * deltaTime, 0);
			}
			if (io.MouseClicked[1] == true)
			{
				float xPosition = 720.0f / 1024.0f;
				float yPosition = 480.0f / 768.0f;
				printf("PosX %f and PosY %f ", xPosition * ImGui::GetMousePos().x, 480 - yPosition * ImGui::GetMousePos().y);
				UI.setSelectedSprite(&background->returnSprite(xPosition * ImGui::GetMousePos().x - (720  / 2) + camera2d->returnCameraPosition().x,480 - yPosition * ImGui::GetMousePos().y - (480 / 2) + camera2d->returnCameraPosition().y));
			}
			camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
			shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			lastTime = currentTime;

		// Render here 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		background->drawBatch();
		//UI.DrawUI();

		// Swap front and back buffers 
		window.update();
	}
}
	texture.unBind();
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	window.closed();
		return 0;
}

