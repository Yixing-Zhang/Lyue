#pragma once

#include "Lyue/Layer.h"
#include "Lyue/Events/MouseEvent.h"
#include "Lyue/Events/KeyEvent.h"
#include "Lyue/Events/ApplicationEvent.h"

namespace Lyue
{

	class LYUE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		// Attributes
		float m_Time = 0.0f;

		// Functions
		// Mouse Event Handlers
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);

		// Key Event Handlers
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);

		// Application Event Handlers
		bool OnWindowResizeEvent(WindowResizeEvent& e);
	};

}