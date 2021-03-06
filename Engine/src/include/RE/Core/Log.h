#pragma once

#include <RE/REpch.h>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#pragma warning(pop)

#ifdef RE_ENGINE
	#define RE_LOGGER() ::RE::Logger::GetEngineLogger()
#else
	#define RE_LOGGER() ::RE::Logger::GetAppLogger()
#endif

#define RE_LOG_INFO(...) RE_LOGGER()->info(__VA_ARGS__)
#define RE_LOG_WARN(...) RE_LOGGER()->warn(__VA_ARGS__)
#define RE_LOG_ERROR(...) RE_LOGGER()->error(__VA_ARGS__)
#define RE_LOG_FATAL(...) RE_LOGGER()->fatal(__VA_ARGS__)

#if RE_DEBUG == 1
	#define RE_LOG_TRACE(...) RE_LOGGER()->trace(__VA_ARGS__)
#else
	#define RE_LOG_TRACE(...)
#endif

namespace RE
{
	class Logger
	{
	public:
		static void RE_API Init();

		static RE_API std::shared_ptr<spdlog::logger>& GetEngineLogger() noexcept;
		static RE_API std::shared_ptr<spdlog::logger>& GetAppLogger() noexcept;

	private:
		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> appLogger;
	};
}