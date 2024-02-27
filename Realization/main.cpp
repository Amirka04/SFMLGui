#include <iostream>

// my gui include lib

#include "Window/Window.h"



int main(){
	Window::create("my gui", 500, 500);
	Window::color(sf::Color(100, 220, 100));



	Window::run();

	return 1;
}
