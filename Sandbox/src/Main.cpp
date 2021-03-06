#include <RE/Core.h>

class SandboxApp : public RE::App
{
public:
	void Run() override
	{
		RE_LOG_INFO("Ready");
		
		while (true);
	}
};

RE_MAIN(SandboxApp);
