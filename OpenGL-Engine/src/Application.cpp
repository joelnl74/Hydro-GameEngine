//#include "../Win32Window.h"
#include "Graphics/Camera2D.h"
#include "Physics/Collision_detection.h"
#include "audio/AudioEngine.h"

#include "HydroEngine.h"
/*
All the code in Application is dummy code just to test some parts of the engine
With right mouse click you can select sprites
Within the spriteEditor you can change properties of the selected sprite
Play makes it possible to move your character sprite around the screen

Notes
------------------------------------------------------------------------
Audio: update to play multiple sound files and also play sounds from streaming instead of loading in to memory[x]
UI:Create sprite[x]
UI:Create layer[x]
Graphics: Create diffrent shader for point light[] 
Graphics/UI: make visible which sprite is selected[]
Camera: movement when in editor mode[]
resource management: rescource management texture/audio/font and so on, at the moment a pointless class[]
FileManager:load scene into engine[x]
FileManager:save scene to xml/json file[x]
Optimize: Drawbatch CPU heavy because we are flushing and building the batch each frame we should only do this if the sprite(gameObject) information has changed[] 
Optimize: algorithm for what the camera cant see wont render[]
Physics: Basic AABB collision detectection [x]
Physics: See if partioning is of world is needed[]
Physics: make the input for adding to the collision map a generic type(sprite rectangle and so on)[x]
Abstract: CameratoScreen function to camera instead of application[x]
Win32Window: Integrate win32 window into project and remove glfw[] 
*/

int main(void)
{
	//create a window
	HydroEngine* m_engine = new HydroEngine();
	ImGuiIO& io = ImGui::GetIO();

	//Simple 2dcamera class
	Camera2D *camera2d = new Camera2D(720, 480);

	Shader *shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();

	shader->SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	shader->setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));

	//create a rederer object from which you can call draw calls
	Collision_detection *detection = new Collision_detection();

	//center camera
	camera2d->centerCamera(64,64);
	shader->SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	
	//Create a audioengine object
	//AudioEngine audio;
	//Load a audio file
	//audio.LoadAudioFileFromSystem("res/sounds/sound1.wav","2", false);
	//audio.LoadAudioFileFromSystem("res/sounds/349179__sirkoto51__rpg-town-loop-2 (1).wav", "RPG", true);
	//TEST BLOCK
	//play the loaded audio file
	//audio.PlaySound("RPG");
	Texture *pointlightTexture = new Texture("res/lighting/pointlight.png");
	Sprite *pointlight = new Sprite(512, 512, 0, 0, false);
	//END
	//Gameloop 
	while (!m_engine->_window->closed())
	{
		//create own Interaction class for UI and Gameplay
		if (io.MouseClicked[0] == true && ImGui::IsAnyItemHovered() == false)
		{
			float xPosition = 720.0f / 1024.0f;
			float yPosition = 480.0f / 768.0f;
			m_engine->_editorUI->setSelectedSprite(m_engine->_layerManager->getLayer(m_engine->_editorUI->returnSelectedLayer())->returnSprite(camera2d->returnWorldToCameraPosition().x,camera2d->returnWorldToCameraPosition().y));
		}
		// Render here 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//CPU heavy because we are flushing and building the batch each frame we should only do this if the sprite(gameObject) information has changed
		shader->Bind();
		m_engine->_layerManager->drawLayers();
		shader->UnBind();
		m_engine->_editorUI->DrawUI();

		// Swap front and back buffers 
		m_engine->_window->update();
}
	delete detection;
	delete camera2d;
	delete shader;
	delete m_engine;
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
		return 0;
}

