//
// Created by cyber_amirka on 27.02.24.
//

#ifndef GUI_OBJECT_H
#define GUI_OBJECT_H

#include <SFML/Graphics.hpp>



class Object{
    public:
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void event(sf::Event event) = 0;

        virtual ~Object() = 0;
};



#endif //GUI_OBJECT_H
