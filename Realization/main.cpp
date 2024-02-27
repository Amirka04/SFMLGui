#include <iostream>

// my gui include lib
#include "Window/Window.h"
#include "Label/label.h"




int main(){
	Window::create("my gui", 500, 500);
	Window::color(sf::Color(120, 120, 120));

	Label *label = new Label("My label", 30);
	label->FocusColor(sf::Color(50, 255, 50));


	Window::push_object(label);


	Window::run();

	return 1;
}
