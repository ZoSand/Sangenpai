#include <TriangleLayer.hpp>

namespace Sangenpai {
	void TriangleLayer::OnAttach()
	{
		std::shared_ptr<Beryllium::VertexBuffer> vertexBuffer;
		std::shared_ptr<Beryllium::IndexBuffer> indexBuffer;

#pragma region data initialize
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//                                                    RENDERER            STUFF                                                     //
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		float vertices[3 * 3] = {
			-.5f, -.5f, 0.f,
			.5f, -.5f, 0.f,
			0.f, .5f, 0.f
		};
		uint32_t indices[3] = {
			0, 1, 2
		};
		/*float vertices[4 * 3] = {
			-1.f, -1.f, 0.f,
			1.f, -1.f, 0.f,
			1.f, 1.f, 0.f,
			-1.f, 1.f, 0.f
		};
		uint32_t indices[3 * 2] = {
			0, 1, 2,
			0, 2, 3
		};*/

		std::string vertexSrc = Beryllium::OpenGLShader::GetDefaultVertex();
		std::string fragmentSrc = Beryllium::OpenGLShader::GetDefaultFragment();
		//END OF TODO
#pragma endregion data initialize

		m_vertexArray.reset(Beryllium::Renderer::CreateVertexArray());

		//setting up buffer layout
		Beryllium::BufferLayout layout = {
			{ Beryllium::ShaderDataType::Float3, "i_Position" }
		};

		vertexBuffer.reset(Beryllium::Renderer::CreateVertexBuffer(vertices, sizeof(vertices) / sizeof(float)));
		vertexBuffer->SetLayout(layout);
		m_vertexArray->AddVertexBuffer(vertexBuffer);

		indexBuffer.reset(Beryllium::Renderer::CreateIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));
		m_vertexArray->SetIndexBuffer(indexBuffer);

		m_shader.reset(Beryllium::Renderer::CreateShader(vertexSrc, fragmentSrc));

		auto& [w, h] = Beryllium::Application::Get()->GetWindow()->GetSize();
		m_mainCamera.SetProjection(-w / h, w / h, -1, 1);
	}

	void TriangleLayer::OnDetach()
	{
	}

	void TriangleLayer::OnUpdate()
	{
		if (Beryllium::Keyboard::IsKeyPressed("D"))
		{
			m_mainCamera.Translate(glm::vec3(1.f * Beryllium::Time::DeltaTime(), 0, 0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("Q"))
		{
			m_mainCamera.Translate(glm::vec3(-.1f, 0, 0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("Z"))
		{
			m_mainCamera.Translate(glm::vec3(0,.1f,  0));
		}
		if (Beryllium::Keyboard::IsKeyPressed("S"))
		{
			m_mainCamera.Translate(glm::vec3(0, -.1f, 0));
		}
	}

	void TriangleLayer::OnRender()
	{
		Beryllium::Renderer::BeginScene(m_mainCamera);
		Beryllium::Renderer::Submit(m_vertexArray, m_shader);
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
