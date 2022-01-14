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

	// Appliaction Layers Operates
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PopOverlay(overlay);
	}

	// Function that Executes when Event e Happens
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		// WindowCloseEvent will be dispatched to OnWindowClose function (close the window)
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		// Events will be passed to the top most layer that can handle it
		// Because the top layers should receive the event first
		// i.e. Click on the screen, the top layer(button) should handle it first.
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	// What Application does when Running
	void Application::Run() 
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

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