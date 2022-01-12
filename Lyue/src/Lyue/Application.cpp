#include "Application.h"

#include "Lyue/Events/ApplicationEvent.h"
#include "Lyue/Log.h"

namespace Lyue {

	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		LY_TRACE(e);

		while (true);
	}

}