//
// Created by cyber_amirka on 27.02.24.
//

#include "Window.h"

#include <iostream>
#include <algorithm>


// static vars
sf::RenderWindow Window::window;
std::list<Object*> Window::_obj;
sf::Color Window::clearColor(0, 0, 0);
sf::Vector2i Window::mouse;


// create window method
void Window::create(const char* caption, int width, int height, int style){
    Window::window.create(sf::VideoMode(width, height), caption, style);
}


// main game loop
void Window::run() {
    while(Window::window.isOpen()) {
        Window::events();
        Window::draw();
        Window::update();
    }
    Window::quit();
}


// set clear color background
void Window::color(sf::Color d_color) {
    Window::clearColor = d_color;
}


// quit
void Window::quit() {
    // free pointer and close main window
    Window::_obj.clear();

    Window::window.close();
}


// добавление объекта для его рендера, событии и каких либо других действий по мере работы программы
void Window::push_object(Object* o) {
    Window::_obj.push_back(o);
}


// удаление объекта из общего списка объектов в будущем планируется сделать именно этот метод автоматизированным или же полуавтоматизированным
// то есть что бы удаление из списка происходило либо через деструктор либо руками человека, но думаю лучше сделать через деструктор
void Window::erase_object(Object* o) {
    Window::_obj.erase( std::remove(Window::_obj.begin(), Window::_obj.end(), o), Window::_obj.end() );
}


// event
void Window::events() {
    sf::Event sfml_event;

    while(Window::window.pollEvent(sfml_event)) {
        if(sfml_event.type == sf::Event::Closed)
            Window::quit();
        std::for_each(
            Window::_obj.begin(),
            Window::_obj.end(),
            [sfml_event](Object* o){ o->event(sfml_event); }
        );
    }
}


// update
void Window::update() {
    // get mouse position
    mouse = sf::Mouse::getPosition(Window::window);


    std::for_each(
        Window::_obj.begin(),
        Window::_obj.end(),
        [](Object* o){ o->update(); }
    );
}


// draw all objects
void Window::draw() {
    Window::window.clear(clearColor);

    std::for_each(
        Window::_obj.begin(),
        Window::_obj.end(),
        [](Object* o){ o->draw(Window::window); }
    );

    Window::window.display();
}

