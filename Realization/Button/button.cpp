// SPDX-FileCopyrightText: 2024 <copyright holder> <email>
// SPDX-License-Identifier: Apache-2.0

#include "button.h"
#include "../Window/Window.h"


Button::Button():label(""){}


Button::Button(const sf::String &labelText, float border)
: label(labelText, 20), border(border), focusFlag(false)
{
    setSize( sf::Vector2f(label.getLocalBounds().width + this->border, label.getLocalBounds().height * 2 + this->border) );
    label.setPosition( sf::Vector2f(getGlobalBounds().top + this->border / 2.f, getGlobalBounds().left + this->border / 2.f) );

    defColor = color = sf::Color{240, 240, 240};
    focusColor = sf::Color{200, 200, 200};

    label.set_color(sf::Color(200, 200, 200));
    label.FocusColor(sf::Color{150, 150, 150});
}


void Button::set_text(const sf::String &text) {
    label.setString(text);
}


void Button::set_size_text(sf::Uint8 font_size) {
    label.setCharacterSize(font_size);
}


void Button::set_size(const sf::Vector2f& size) {
    setSize( (label.getGlobalBounds().width > size.x && label.getGlobalBounds().height > size.y) ? sf::Vector2f(label.getGlobalBounds().width, label.getGlobalBounds().height) : size );
}


void Button::set_pos(const sf::Vector2f &new_pos) {
    setPosition(new_pos);
    label.setPosition( sf::Vector2f(getGlobalBounds().top + this->border / 2.f, getGlobalBounds().left + this->border / 2.f) );
}


void Button::set_focus_color(const sf::Color &color) {
    focusColor = color;
}


void Button::set_color(const sf::Color &color) {
    defColor = this->color = color;
}


bool isClicked() {
    // comin
    return false;
}


void Button::update() {
    color = defColor;
    label.setFocus(false);
    if(focusFlag) {
        label.setFocus(true);
        color = focusColor;
    }
    setFillColor(color);
    label.update();
}


void Button::draw(sf::RenderWindow &window) {
    window.draw(*this);
    label.draw(window);
}


void Button::event(sf::Event e) {
    if(e.type == sf::Event::MouseMoved)
        if( e.mouseMove.x >= getPosition().x && e.mouseMove.y >= getPosition().y \
             && e.mouseMove.x <= getPosition().x + getGlobalBounds().width && e.mouseMove.y <= getPosition().y + getGlobalBounds().height)
            focusFlag = true;
        else
            focusFlag = false;


    if(e.type == sf::Event::MouseButtonPressed)
        if(focusFlag)
            std::cout << "Button clicked!" << std::endl;
}