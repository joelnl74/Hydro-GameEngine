#pragma once
#include <string>
#include <fstream>
#include <Windows.h>

#define LOG_ERROR(x)     Logger::m_Instance->Error(x)
#define LOG_WARNING(x)   Logger::m_Instance->Warning(x)
#define LOG_CRITICAL(x)	 Logger::m_Instance->Critical(x)
#define LOG_INFO(x)      Logger::m_Instance->Info(x)
#define LOG_DEBUG(x)     Logger::m_Instance->Debug(x)

typedef enum LOG_LEVEL
{
	DISABLE_LOG = 1,
	LOG_LEVEL_INFO = 2,
	LOG_LEVEL_BUFFER = 3,
	LOG_LEVEL_TRACE = 4,
	LOG_LEVEL_DEBUG = 5,
	ENABLE_LOG = 6,
}LogLevel;

// enum for LOG_TYPE
typedef enum LOG_TYPE
{
	NO_LOG = 1,
	CONSOLE = 2,
	FILE_LOG = 3,
}LogType;

class Logger
{
public:

	void Error(const char* text)    throw();
	void Warning(const char* text)  throw();
	void Critical(const char* text) throw();
	void Info(const char* text)		throw();
	void Debug(const char* text)    throw();

	void StartUp();
	void ShutDown();
	static Logger *m_Instance;
	std::fstream _loggerFile;
private:
	void LogOnConsole(std::string &message);
	void LogToFile(std::string &message);
	std::string getCurrentTime();

	LogType _logType;
	LogLevel _logLevel;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

