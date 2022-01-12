#include "Application.h"

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
		if (e.IsInCategory(EventCategoryApplication))
		{
			LY_TRACE(e);
		}
		
		if (e.IsInCategory(EventCategoryInput))
		{
			LY_TRACE(e);
		}
		
		while (true);
	}

}