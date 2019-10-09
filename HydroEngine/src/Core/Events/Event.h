#pragma once
#include <string>

enum EventType
{
	None = 0,
	WindowResize,
	WindowClosed,
};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

class Event
{
public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual std::string ToString() const { return GetName(); }
};

class EventDispatcher
{
public:
	EventDispatcher(Event& event) : m_Event(event)	{}
	
private:
	Event &m_Event;
};

class EventBus
{
	// Holds all the events and dispatched them at a certain point in the mainloop

	void DispatchEvents()
	{

	}
};