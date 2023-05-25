#ifndef	SGP_APPLICATION_HPP
#define	SGP_APPLICATION_HPP

#	include <Beryllium.hpp>

namespace Sangenpai
{
	class Application : public Beryllium::Application
	{
	public:
		Application(Beryllium::ApplicationSpecs _specs);
		~Application();

		virtual bool OnEvent(Beryllium::Event& _event) override;
	};
}

#endif // SGP_APPLICATION_HPP