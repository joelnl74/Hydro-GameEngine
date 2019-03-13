#pragma once
#include "../Input.h"


class WindowsInput : public Input
{
public:
	inline static Input &GetInstance()
	{
		if (s_Instance != nullptr)
			return *s_Instance;

		s_Instance = new WindowsInput();
	}
protected:
	virtual bool IsKeyPressedImpl(int keycode) override;

	virtual bool IsMouseButtonPressedImpl(int button) override;
	virtual std::pair<float, float> GetMousePositionImpl() override;
	virtual float GetMouseXImpl() override;
	virtual float GetMouseYImpl() override;

	virtual void StartUp(GLFWwindow * window) override;
	virtual void ShutDown() override;


};