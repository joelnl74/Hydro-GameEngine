//#include "../Win32Window.h"
#include "Graphics/Window.h"
#include "Graphics/Layer.h"
#include "Graphics/Camera2D.h"

#include "audio/AudioEngine.h"
#include "EngineUI/EditorUI.h"
enum State
{
	Editor,
	Play

};

const int WIDTH  = 1024;
const int HEIGHT = 768;

//class TestApp : public Win32Window
//{
//public:
//	TestApp(HINSTANCE hIstance);
//	~TestApp();
//	bool Init() override;
//	void Update(float dt) override;
//	void Render() override;
//	LRESULT MsgProc(HWND hwndm, UINT msg, WPARAM wParam, LPARAM lParam) override;
//};
//TestApp::TestApp(HINSTANCE hIstance) : Win32Window(hIstance)
//{
//
//}
//
//TestApp::~TestApp()
//{
//
//}
//bool TestApp::Init()
//{
//	if (!Win32Window::Init())
//		return false;
//
//	return true;
//}
//void TestApp::Update(float dt)
//{
//
//}
//void TestApp::Render()
//{
//
//}
//LRESULT TestApp::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//		default:
//		{
//			return Win32Window::MsgProc(hwnd, msg, wParam, lParam);
//			break;
//		}			
//	}
//}
//
//int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevIstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	TestApp app(hinstance);
//	if (!app.Init())
//		return 1;
//
//	return app.Run();
//}
int main(void)
{
	double lastTime = glfwGetTime();
	double deltaTime = 1.0 / 30;

	State engineMode = State::Editor;

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	//create a window
	Window window(WIDTH, HEIGHT, "Hydro Engine");
	EditorUI UI(window.getWindow());

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));

	//Simple 2dcamera class
	Camera2D *camera2d = new Camera2D(720, 480);

	Shader shader = Shader("res/shaders/Basic.shader");
	shader.Bind();

	shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	shader.setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));

	//create a rederer object from which you can call draw calls
	Layer background;

	//create a texture
	Texture texture = Texture("res/textures/Tiles.png");

	int xX = 0;
	int yY = 0;
	//test code for rendering a lot sprites
	for (int i = 0; i < 20024; i++)
	{
		Sprite *m_sprite = new Sprite(32, 32, 32 * xX, 32 * yY);
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
		background.submitSprite(*m_sprite);
	}
	Sprite *m_player = new Sprite(32, 32, 400, 300);
	m_player->setIndex(4, 4);
	m_player->setTextureUV(1, 1);
	background.submitSprite(*m_player);

	//Create a audioengine object
	//AudioEngine engine;
	//Load a audio file
	//engine.LoadAudioFileFromSystem("res\sounds\sound1.wav");
	//play the loaded audio file
	//engine.PlaySound();

	int playerspeed_x = 32;
	int playerspeed_y = 32;

	//Gameloop 
	while (!window.closed())
	{
		ImGuiIO& io = ImGui::GetIO();
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
				printf("Pressed S key");
			}

			camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
			shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			lastTime = currentTime;

		// Render here 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		texture.bind();
		background.drawBatch();
		texture.unBind();

		UI.DrawUI(*m_player);

		// Swap front and back buffers 
		window.update();
	}
}
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	window.closed();
		return 0;
}

