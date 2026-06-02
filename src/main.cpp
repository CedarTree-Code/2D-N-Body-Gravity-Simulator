#include <SFML/Window.hpp>
using namespace sf;

int main()
{
	Window window(VideoMode({800, 600}), "Window fr");

	while(window.isOpen()){
		while(const std::optional event = window.pollEvent()){
			if(event->is<Event::Closed>())
				window.close();
		}
	}
}
