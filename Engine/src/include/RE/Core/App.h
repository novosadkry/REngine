#pragma once
#include <RE/REpch.h>

namespace RE
{
	class RE_API App
	{
	public:
		App();
		virtual ~App();

		virtual void Run();
	};
}
