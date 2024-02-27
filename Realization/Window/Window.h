//
// Created by cyber_amirka on 27.02.24.
//

#ifndef WINDOW_H
#define WINDOW_H


#include <SFML/Graphics.hpp>
#include "../gui_object.h"



class Window {
public:
        static void create(const char* caption,int width, int height, int stype = sf::Style::Default);
        static void run();
        static void color(sf::Color);
        static void quit();

        static void AttachObject(Object*);
        static void DettachObject(Object*);

private:
        // static method
        static void events();
        static void update();
        static void draw();

        // static values
        static sf::RenderWindow window;
        static sf::Color clearColor;
        static std::vector<Object*> _obj;

};



#endif //WINDOW_H
