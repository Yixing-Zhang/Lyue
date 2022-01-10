#pragma once

#include "Core.h"

namespace Lyue
{

	class LYUE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in the actual applicaiton
	Application* CreateApplication();

}
