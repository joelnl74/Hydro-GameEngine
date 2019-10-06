#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#define LOG_ERROR(...)		 Logger::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_WARNING(...)     Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CRITICAL(...)    Logger::GetCoreLogger()->fatal(__VA_ARGS__)
#define LOG_INFO(...)		 Logger::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_DEBUG(...)		 Logger::GetCoreLogger()->trace(__VA_ARGS__)

namespace Hydro
{
	class Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_Instance; };

	private:
		static std::shared_ptr<spdlog::logger> s_Instance;
	};
}

