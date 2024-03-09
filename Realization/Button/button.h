// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: Apache-2.0

#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../gui_object.h"
#include "label.h"



class Button : public sf::RectangleShape, public Object
{
public:
    // constructor
    Button();
    Button(const sf::String& labelText, float border = 10);

    // settters
    void set_text(const sf::String& text);
    void set_size_text(sf::Uint8 font_size);
    void set_size(const sf::Vector2f& size);
    void set_pos(const sf::Vector2f& new_pos);
    void set_focus_color(const sf::Color& color);
    void set_color(const sf::Color& color);

    bool isClicked();

    void update() override;
    void draw(sf::RenderWindow& window) override;
    void event(sf::Event e) override;

    // destructor
    ~Button() = default;
protected:
    sf::Color focusColor;
    sf::Color color;
    sf::Color defColor;
    float border;
    bool focusFlag;
    Label label;
};

#endif // BUTTON_H
