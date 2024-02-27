#include <iostream>

// my gui include lib
#include "Window/Window.h"
#include "Label/label.h"




int main(){
	Window::create("my gui", 500, 500);
	Window::color(sf::Color(100, 220, 100));

	Label *label = new Label("My Label");

	Window::AttachObject(label);


	Window::run();

	return 1;
}
