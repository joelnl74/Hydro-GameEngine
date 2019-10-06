#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hydro
{
	std::shared_ptr<spdlog::logger> Logger::s_Instance;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Instance = spdlog::stdout_color_mt("HYDRO");
		s_Instance->set_level(spdlog::level::trace);
	}
}