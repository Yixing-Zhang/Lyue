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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		// Attributes
		float m_Time = 0.0f;
	};

}