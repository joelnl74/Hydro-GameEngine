#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"

#include <iostream>
#include <ctime>
#include <chrono>

const std::string FileLocation = "Logging/LogFile.txt";
Logger *Logger::m_Instance = 0;

void Logger::StartUp()
{
	if (m_Instance == 0)
	{
		m_Instance = new Logger();
		m_Instance->_logType = LOG_TYPE::FILE_LOG;
		m_Instance->_loggerFile.open(FileLocation);

		if (m_Instance->_loggerFile.is_open() == false)
		{
			m_Instance->Critical("Could not open loggerFile!");
		}
	}
}
void Logger::ShutDown()
{
	_loggerFile.close();
	delete m_Instance;
}
void Logger::LogOnConsole(std::string &message)
{
	if (_logType >= LOG_TYPE::CONSOLE)
	{
		std::cout << getCurrentTime() << " " << message << std::endl;
	}
}
void Logger::LogToFile(std::string &message)
{
	if (_logType >= LOG_TYPE::FILE_LOG)
	{
		_loggerFile << getCurrentTime() + ": " + message + "\n";
	}
}
void Logger::Error(const char* text)
{
	SetConsoleTextAttribute(hConsole, 4);

	_ASSERT(m_Instance);
	std::string data;
	data.append("[Error]: ");
	data.append(text);

	LogToFile(data);
	LogOnConsole(data);
}
void Logger::Warning(const char* text)
{
	SetConsoleTextAttribute(hConsole, 14);

	_ASSERT(m_Instance);
	std::string data;
	data.append("[Warning]: ");
	data.append(text);

	LogToFile(data);
	LogOnConsole(data);
}
void Logger::Critical(const char* text)
{
	SetConsoleTextAttribute(hConsole, 4);

	_ASSERT(m_Instance);
	std::string data;
	data.append("[Critical]: ");
	data.append(text);

	LogToFile(data);
	LogOnConsole(data);
}
void Logger::Info(const char* text)
{
	SetConsoleTextAttribute(hConsole, 15);

	_ASSERT(m_Instance);
	std::string data;
	data.append("[Info]: ");
	data.append(text);

	LogToFile(data);
	LogOnConsole(data);
}
void Logger::Debug(const char* text)
{
	SetConsoleTextAttribute(hConsole, 15);

	_ASSERT(m_Instance);
	std::string data;
	data.append("[Debug]: ");
	data.append(text);

	LogToFile(data);
	LogOnConsole(data);
}
std::string Logger::getCurrentTime()
{
	std::string currTime;
	//Current date/time based on current time
	time_t now = time(0);
	// Convert current time to string
	currTime.assign(ctime(&now));

	// Last charactor of currentTime is "\n", so remove it
	std::string currentTime = currTime.substr(0, currTime.size() - 1);
	return currentTime;
}
