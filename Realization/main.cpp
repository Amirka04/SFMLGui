#include <iostream>

// my gui include lib
#include "Window/Window.h"
#include "Label/label.h"
#include "Button/button.h"



int main(){
	Window::create("my gui", 500, 500);
	Window::color(sf::Color(120, 120, 120));

	Button* button = new Button("This is button", 10);
	button->set_pos(sf::Vector2f{100, 100});

	Window::push_object(button);


	Window::run();

	return EXIT_SUCCESS;
}
