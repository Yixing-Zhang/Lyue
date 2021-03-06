#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Lyue
{

	class LYUE_API Log
	{
	public:
		// Initializing the Loggers
		static void Init();

		// Logger Getters
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		// Engine Core Logger
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		// Application Client Loggers
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define LY_CORE_TRACE(...)		::Lyue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LY_CORE_INFO(...)		::Lyue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LY_CORE_WARN(...)		::Lyue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LY_CORE_ERROR(...)		::Lyue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LY_CORE_FATAL(...)		::Lyue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LY_TRACE(...)		::Lyue::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LY_INFO(...)		::Lyue::Log::GetClientLogger()->info(__VA_ARGS__)
#define LY_WARN(...)		::Lyue::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LY_ERROR(...)		::Lyue::Log::GetClientLogger()->error(__VA_ARGS__)
#define LY_FATAL(...)		::Lyue::Log::GetClientLogger()->fatal(__VA_ARGS__)


