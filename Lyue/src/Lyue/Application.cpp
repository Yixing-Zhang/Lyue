#include "lypch.h"
#include "Application.h"

#include "Lyue/Log.h"
#include "Lyue/Input.h"

#include <glad/glad.h>

namespace Lyue {

	// Singleton
	Application* Application::s_Instance = nullptr;

	// Constructor
	Application::Application() 
	{
		LY_CORE_ASSERT(!s_Instance, "Application already exists!");

		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(LY_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	// Destructor
	Application::~Application() 
	{

	}

	// Appliaction Layers Operates
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	// Function that Executes when Event e Happens
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		// WindowCloseEvent will be dispatched to OnWindowClose function (close the window)
		dispatcher.Dispatch<WindowCloseEvent>(LY_BIND_EVENT_FN(Application::OnWindowClose));

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

			// Layers update
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			// Layers on ImGui Update
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			// Window update
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