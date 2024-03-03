// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: Apache-2.0

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "../gui_object.h"
#include <SFML/Graphics.hpp>


class Button : public sf::RectangleShape, public Object
{
public:
    Button();
    Button(const sf::String& labelText, const sf::Vector2f& size);

    ~Button();
protected:
    sf::String string = "Побороть лень!";
};

#endif // BUTTON_H
