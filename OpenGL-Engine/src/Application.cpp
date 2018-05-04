//#include "../Win32Window.h"
#include "Graphics\Window.h"
#include "Graphics/Renderer.h"
#include "Graphics/Layer.h"
#include "Graphics/Camera2D.h"
#include "Graphics/Text.h"

#include "audio/AudioEngine.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw_gl3.h"
#include <vector>
#include <iterator>

#define Editor 1

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

	bool spriteEditor = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	//create a window
	Window window(WIDTH, HEIGHT, "Hydro Engine");

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));

	//Simple 2dcamera class
	Camera2D *camera2d = new Camera2D(720, 480);

	Shader shader = Shader("res/shaders/Basic.shader");
	shader.Bind();

	shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
	shader.setVec3("ambientLight", glm::vec3(0.85f, 0.85f, 0.85f));

	//create a rederer object from which you can call draw calls
	Renderer renderer;
	Layer background;

	//create a texture
	Texture texture = Texture("res/textures/Tilesheet.png");

	int xX = 0;
	int yY = 0;
	//test code for rendering a lot sprites
	for (int i = 0; i < 20024; i++)
	{
		Sprite *m_sprite = new Sprite(32, 32, 32 * xX, 32 * yY);
		m_sprite->setIndex(16, 8);
		m_sprite->setTextureUV(4, 1);
		if (xX == 0 || yY == 0 || yY == 141)
		{
			m_sprite->setTextureUV(6, 1);
		}
		xX++;
		if (xX == 141)
		{
			m_sprite->setTextureUV(6, 1);
			yY++;
			xX = 0;
		}
		background.submitSprite(*m_sprite);
	}
	Sprite *m_player = new Sprite(32, 32, 400, 300);
	m_player->setIndex(16, 8);
	m_player->setTextureUV(0, 0);
	background.submitSprite(*m_player);

	float position[2];
	position[0] = m_player->getPosition().x;
	position[1] = m_player->getPosition().y;

	float scale[2];
	scale[0] = m_player->getScale().x;
	scale[1] = m_player->getScale().y;

	//Create a audioengine object
	//AudioEngine engine;
	//Load a audio file
	//engine.LoadAudioFileFromSystem("res\sounds\sound1.wav");
	//play the loaded audio file
	//engine.PlaySound();

	int playerspeed_x = 32;
	int playerspeed_y = 32;

	if (Editor == 1)
	{
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window.getWindow(), true);
		ImGui::StyleColorsLight();
	}
	//Gameloop 
	while (!window.closed())
	{
		double currentTime = glfwGetTime();
		if (currentTime - lastTime >= deltaTime) {

			if (window.isKeyPressed(GLFW_KEY_A))
			{
				m_player->TransLate(-playerspeed_x * 9.81f * deltaTime, 0, 0);
			}
			if (window.isKeyPressed(GLFW_KEY_D))
			{
				m_player->TransLate(playerspeed_x* 9.81f * deltaTime, 0, 0);
			}
			if (window.isKeyPressed(GLFW_KEY_W))
			{
				m_player->TransLate(0, playerspeed_y * 9.81f * deltaTime, 0);
			}
			if (window.isKeyPressed(GLFW_KEY_S))
			{
				m_player->TransLate(0, -playerspeed_y * 9.81f * deltaTime, 0);
				printf("Pressed S key");
			}

			camera2d->centerCamera(m_player->getPosition().x, m_player->getPosition().y);
			shader.SetMatrix4("orthographicModel", camera2d->returnOrthographicCamera());
			lastTime = currentTime;

		// Render here 
		renderer.Clear();

		texture.bind();
		background.drawBatch();
		texture.unBind();

			if (Editor == 1)
			{
				ImGui_ImplGlfwGL3_NewFrame();

				ImGui::BeginMainMenuBar();
				ImGui::MenuItem("SpriteEditor", NULL, &spriteEditor);
				ImGui::EndMainMenuBar();
				
				if (spriteEditor == true)
				{
					ImGui::Begin("SpriteEditor");

					ImGuiIO& io = ImGui::GetIO();

					ImGui::Text("SpritePosition");
					ImGui::InputFloat2("", position);

					ImGui::Text("SpriteSize");
					ImGui::InputFloat2(" ", scale);
					if (ImGui::Button("Submit", ImVec2(50, 50)))
					{
						m_player->setPosition(position[0], position[1]);
						m_player->Scale(scale[0], scale[1], 0);
					}
					ImGui::End();
				}
				ImGui::Render();
				ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
		}
		// Swap front and back buffers 
		window.update();
	}
}
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	window.closed();
		return 0;
}

