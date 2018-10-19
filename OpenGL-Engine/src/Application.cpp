//#include "../Win32Window.h"
#include "Physics/Collision_detection.h"

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
	Engine::HydroEngine* m_engine = new Engine::HydroEngine();

	//create a rederer object from which you can call draw calls
	//Collision_detection *detection = new Collision_detection();
	
	//Create a audioengine object
	//Load a audio file
	//m_engine->_audioEngine->LoadAudioFileFromSystem("res/sounds/sound1.wav","2", false);
	//m_engine->_audioEngine->LoadAudioFileFromSystem("res/sounds/349179__sirkoto51__rpg-town-loop-2 (1).wav", "RPG", true);
	//TEST BLOCK
	//play the loaded audio file
	// m_engine->_audioEngine->PlaySound("RPG");
	//Texture *pointlightTexture = new Texture("res/lighting/pointlight.png");
	//Sprite *pointlight = new Sprite(512, 512, 0, 0, false);
	//END

	//Gameloop 
	while (!m_engine->_window->closed())
	{		//create own Interaction class for UI and Gameplay
		m_engine->CheckInput();
		// Render here 
		m_engine->Draw();
    }
	//delete detection;
	delete m_engine;
		return 0;
}

