#ifndef SGP_TRIANGLE_LAYER_HPP
#define SGP_TRIANGLE_LAYER_HPP

#include <Beryllium.hpp>

namespace Sangenpai
{
	class TriangleLayer : public Beryllium::Layer
	{
	public:
		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnRender() override;
		virtual bool OnEvent(Beryllium::Event& _event) override;

	private:
		Beryllium::Sprite m_sprite;

		Beryllium::OrthographicCamera m_mainCamera;
	};
}

#endif // 
