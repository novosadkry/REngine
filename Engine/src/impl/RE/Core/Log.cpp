#include <RE/REpch.h>
#include <RE/Core/Log.h>

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> RE::Logger::engineLogger;
std::shared_ptr<spdlog::logger> RE::Logger::appLogger;

void RE::Logger::Init()
{
	try
	{
		spdlog::set_pattern("[%T] %-6n | %^%-7l%$ >> %v");
		
		engineLogger = spdlog::stdout_color_mt("Engine");
		engineLogger->set_level(spdlog::level::trace);

		appLogger = spdlog::stdout_color_mt("App");
		appLogger->set_level(spdlog::level::trace);

		RE_LOG_TRACE("{} successful", __FUNCTION__);
	}

	catch (spdlog::spdlog_ex& err)
	{
		RE_LOG_ERROR("{} failed : {}", __FUNCTION__, err.what());
	}
}

std::shared_ptr<spdlog::logger>& RE::Logger::GetEngineLogger() noexcept
{
	return engineLogger;
}

std::shared_ptr<spdlog::logger>& RE::Logger::GetAppLogger() noexcept
{
	return appLogger;
}