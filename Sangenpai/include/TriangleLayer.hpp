#ifndef SGP_TRIANGLE_LAYER_HPP
#define SGP_TRIANGLE_LAYER_HPP

#include <Beryllium.hpp>

namespace Sangenpai
{
	class TriangleLayer : public Beryllium::Layer
	{
	public:
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual bool OnEvent(Beryllium::Event& _event) override;

	private:
		std::shared_ptr<Beryllium::VertexArray> m_vertexArray;
		std::shared_ptr<Beryllium::Shader> m_shader;
	};
}

#endif // 
