#include "lypch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lyue
{
	
	// Engine Core Logger
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	// Application Client Loggers
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	// Initializing the Loggers
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Lyue");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
