#include "lypch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Lyue/Log.h"

namespace Lyue {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	// Constructor
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	// Destructor
	Application::~Application() 
	{

	}

	// Function that Executes when Event e Happens
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		LY_CORE_TRACE("{0}", e);
	}

	// What Application does when Running
	void Application::Run() 
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}

	// Function that Executes when Window Closed
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}

}