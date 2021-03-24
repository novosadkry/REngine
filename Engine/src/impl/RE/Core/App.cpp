#include <RE/REpch.h>
#include <RE/Core.h>

namespace RE
{
	App::App() = default;
	App::~App() = default;

	void App::Run()
	{
		Logger::Init();
		RE_LOG_INFO("Ready");

		while (true);
	}
}
