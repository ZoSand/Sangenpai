#include <TriangleLayer.hpp>

namespace Sangenpai {
	void TriangleLayer::OnAttach()
	{
		auto& [w, h] = Beryllium::Application::Get()->GetWindow()->GetSize();
		m_mainCamera.SetProjection(-w / h, w / h, -1, 1);
	}

	void TriangleLayer::OnUpdate()
	{
		if (Beryllium::Keyboard::IsKeyPressed("D"))
		{
			m_mainCamera.Translate(glm::vec3(1.f * Beryllium::Time::DeltaTime(), 0, 0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("Q"))
		{
			m_mainCamera.Translate(glm::vec3(-1.f * Beryllium::Time::DeltaTime(), 0, 0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("Z"))
		{
			m_mainCamera.Translate(glm::vec3(0, 1.f * Beryllium::Time::DeltaTime(),  0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("S"))
		{
			m_mainCamera.Translate(glm::vec3(0, -1.f * Beryllium::Time::DeltaTime(), 0));
		}

		if (Beryllium::Keyboard::IsKeyPressed("escape"))
		{
			Beryllium::Application::Get()->Quit();
		}
	}

	void TriangleLayer::OnRender()
	{
		Beryllium::Renderer::BeginScene(m_mainCamera);
		Beryllium::Renderer::Submit(m_sprite);
		Beryllium::Renderer::EndScene();
	}

	bool TriangleLayer::OnEvent(Beryllium::Event& _event)
	{
		if (_event.Is<Beryllium::Events::WindowResized>())
		{
			auto& [w, h] = Beryllium::Application::Get()->GetWindow()->GetSize();
			m_mainCamera.SetProjection(-w / h, w / h, -1, 1);
		}
		return false; //we don't want to block event propagation to other layers
	}
}
