//#include "../Win32Window.h"
#include "Graphics/Window.h"
#include "Graphics/Layer.h"
#include "Graphics/Camera2D.h"
#include "Physics/Collision_detection.h"

#include "audio/AudioEngine.h"
#include "EngineUI/EditorUI.h"

/*
All the code in Application is dummy code just to test some parts of the engine
With right mouse click you can select sprites
Within the spriteEditor you can change properties of the selected sprite
Play makes it possible to move your character sprite around the screen

Notes
------------------------------------------------------------------------
Audio: update to play multiple sound files and also play sounds from streaming instead of loading in to memory
UI:Create sprite[]
UI:Create layer[]
Graphics: Create diffrent shader for point light[] 
Graphics/UI: make visible which sprite is selected[]
Camera: movement when in editor mode[]
resource management: rescource management texture/audio/font and so on, at the moment a pointless class[]
FileManager:load scene into engine[]
FileManager:save scene to xml/json file[]
Optimize: Drawbatch CPU heavy because we are flushing and building the batch each frame we should only do this if the sprite(gameObject) information has changed[] 
Optimize: algorithm for what the camera cant see wont render[]
Physics: Basic AABB collision detectection []
Physics: See if partioning is of world is needed[]
Physics: make the input for adding to the collision map a generic type(sprite rectangle and so on)[]
Abstract: CameratoScreen function to camera instead of application[x]
Win32Window: Integrate win32 window into project and remove glfw[] 
*/
 int WIDTH  = 1024;
 int HEIGHT = 768;

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
	Collision_detection *detection = new Collision_detection();
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
			detection->addBoundingBox(m_sprite->getPosition(), m_sprite->getScale());
		}
		xX++;
		if (xX == 141)
		{
			m_sprite->setTextureUV(1, 0);
			detection->addBoundingBox(m_sprite->getPosition(), m_sprite->getScale());
			yY++;
			xX = 0;
		}
		background->submitSprite(*m_sprite);
	}

	Sprite *m_player = new Sprite(32, 32, 64, 64);
	m_player->setIndex(4, 4);
	m_player->setTextureUV(1, 1);
	background->submitSprite(*m_player);

	//center camera
	camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
	shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	
	//Create a audioengine object
	//AudioEngine audio;
	//Load a audio file
	//audio.LoadAudioFileFromSystem("res/sounds/sound1.wav");
	//play the loaded audio file
	//audio.PlaySound();

	int playerspeed_x = 32;
	int playerspeed_y = 32;

	texture.bind();
	//Gameloop 
	while (!window.closed())
	{
		double currentTime = glfwGetTime();
		if (currentTime - lastTime >= deltaTime) {

			detection->checkCollision(m_player->getPosition(), m_player->getScale());
			if (ImGui::IsKeyDown(GLFW_KEY_A) && UI.returnPlay())
			{
				m_player->TransLate(-playerspeed_x * 9.81f * deltaTime, 0);
				camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
				shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			}
			if (ImGui::IsKeyDown(GLFW_KEY_D) && UI.returnPlay())
			{
				m_player->TransLate(playerspeed_x* 9.81f * deltaTime, 0);
				camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
				shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			}
			if (ImGui::IsKeyDown(GLFW_KEY_W) && UI.returnPlay())
			{
				m_player->TransLate(0, playerspeed_y * 9.81f * deltaTime);
				camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
				shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			}
			if (ImGui::IsKeyDown(GLFW_KEY_S) && UI.returnPlay())
			{
				m_player->TransLate(0, -playerspeed_y * 9.81f * deltaTime);
				camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
				shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			}
			if (io.MouseClicked[1] == true)
			{
				float xPosition = 720.0f / 1024.0f;
				float yPosition = 480.0f / 768.0f;
				UI.setSelectedSprite(&background->returnSprite(camera2d->returnWorldToCameraPosition().x, camera2d->returnWorldToCameraPosition().y));
			}
			lastTime = currentTime;

		// Render here 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//CPU heavy because we are flushing and building the batch each frame we should only do this if the sprite(gameObject) information has changed
		background->drawBatch();
		UI.DrawUI();

		// Swap front and back buffers 
		window.update();
	}
}
	texture.unBind();
	delete detection;
	delete background;
	delete camera2d;
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	window.closed();
		return 0;
}

