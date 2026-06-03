#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

struct Planet {

	float Xpos, Ypos, Xvel, Yvel, Xacc, Yacc, size;
	Color colour;
	CircleShape shape;

	Planet() {
		Xpos = Ypos = Xvel = Yvel = Xacc = Yacc = size = 0.f; colour = Color::White;
		shape.setRadius(size);
		shape.setOrigin({size, size});
		shape.setFillColor(colour);
	}

	Planet(float xpos, float ypos, float xvel, float yvel, float xacc, float yacc, float S, Color C) {
		Xpos = xpos; Ypos = ypos; //initial position
		Xvel = xvel; Yvel = yvel; //initial velocity
		Xacc = xacc; Yacc = yacc; //initial acceleration
		size = S; colour = C;

		//setup Planet shape for display
		shape.setRadius(size);
		shape.setOrigin({size, size});
		shape.setFillColor(colour);
	}

	void update(float dt) {
		Xvel += Xacc * dt; 
		Yvel += Yacc * dt;
		Xpos += Xvel * dt;
		Ypos += Yvel * dt;
	}

};

int main() {

	//----SETUP----//

	//RenderWindow window(VideoMode::getDesktopMode(), "Drawing a circle", State::Fullscreen);
	RenderWindow window(VideoMode({1600, 900}), "Drawing a circle");
	float height = window.getSize().x;
	float width = window.getSize().y;

	Planet earth (height/2, width/2, 200.f, -200.f, 0.f, 350.f, 100.f, Color::Blue);

	Clock clock; //start timing
	Time time1 = clock.getElapsedTime(), time2, Dtime; 	//Dtime is (Delta) change in time
	
	while(window.isOpen()) {

		while(const std::optional event = window.pollEvent()) {
			if(event->is<Event::Closed>()) 
				window.close();
			else if(const auto* keyPressed = event->getIf<Event::KeyPressed>()) {
				if(keyPressed->scancode == Keyboard::Scancode::Escape) 
					window.close();
			}
		}

		//----DISPLAY CYCLE----//

		//clear screen
		window.clear(Color::Black); 

		//draw shapes
		earth.shape.setPosition({earth.Xpos, earth.Ypos});
		window.draw(earth.shape); 

		//update time and object
		time2 = clock.getElapsedTime();
		Dtime = time2-time1;
		time1 = time2;

		earth.update(Dtime.asSeconds());

		window.display();

	}

	std::cout << "Window closed!" << std::endl;

}
