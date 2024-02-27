// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: Apache-2.0

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Button : public sf::RectangleShape
{
public:
    Button();
    Button(const sf::String& labelText, const sf::Vector2f& size);

    ~Button();
protected:

};

#endif // BUTTON_H
