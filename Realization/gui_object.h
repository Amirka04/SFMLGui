//
// Created by cyber_amirka on 27.02.24.
//

#ifndef GUI_OBJECT_H
#define GUI_OBJECT_H

#include <SFML/Graphics.hpp>



class Object{
    public:
        virtual void draw(sf::RenderWindow&){};
        virtual void update(){};
        virtual void event(sf::Event e){};
        virtual ~Object() = default;
};



#endif //GUI_OBJECT_H
