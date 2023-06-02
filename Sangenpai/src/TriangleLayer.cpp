#include <TriangleLayer.hpp>

namespace Sangenpai {

	void TriangleLayer::OnAttach()
	{
		std::shared_ptr<Beryllium::VertexBuffer> vertexBuffer;
		std::shared_ptr<Beryllium::IndexBuffer> indexBuffer;

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

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 i_Position;
			out vec3 t_Position;

			void main()
			{
				gl_Position = vec4(i_Position, 1.0);
				t_Position = i_Position; 
			}
		)";
		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 o_Color;
			in vec3 t_Position;

			vec4 remap(vec4 _val, vec2 _min, vec2 _max)
			{
				return _max.x + (_val - _min.x) * (_max.y -  _max.x) / (_min.y - _min.x);
			}

			void main()
			{
				o_Color = vec4(0.8, 0.2, 0.3, 0.5);
				o_Color = remap(vec4(t_Position, 0.5), vec2(-1, 1), vec2(0, 1));
			}
		)";
		//END OF TODO

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
	}

	void TriangleLayer::OnDetach()
	{
	}

	void TriangleLayer::OnUpdate()
	{
		m_shader->Bind();
		Beryllium::Renderer::Submit(m_vertexArray);
	}

	bool TriangleLayer::OnEvent(Beryllium::Event& _event)
	{
		return false;
	}
}
