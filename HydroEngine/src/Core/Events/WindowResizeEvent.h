#pragma once
#include "Event.h"
#include <sstream>
class WindowResizeEvent : public Event
{
public:
	inline unsigned int GetWidth() const { return m_Width; }
	inline unsigned int GetHeight() const { return m_Height; }

	WindowResizeEvent(unsigned int width, unsigned int height)
		: m_Width(width), m_Height(height) {}

	std::string ToString() const override
	{
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
		return ss.str();
	};

	EVENT_CLASS_TYPE(WindowResize)

private:
	unsigned int m_Width;
	unsigned int m_Height;
};
