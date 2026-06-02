#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {

	RenderWindow window(VideoMode(), "Drawing a circle", State::Fullscreen);
	float height = window.getSize().x;
	float width = window.getSize().y;

	CircleShape circle(100.f);
	circle.setOrigin({100.f, 100.f});
	circle.setPosition({height/2, width/2});
	circle.setFillColor(Color::Blue);

	while(window.isOpen()) {

		while(const std::optional event = window.pollEvent()) {
			if(event->is<Event::Closed>()) 
				window.close();
			else if(const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
				if(keyPressed->scancode == Keyboard::Scancode::Escape) 
					window.close();
			}
		}

		window.clear(Color::Black);
		window.draw(circle); //draw stuff
		window.display();

	}

	std::cout << "Window closed!" << std::endl;

}
