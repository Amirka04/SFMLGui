#include "label.h"
#include "../Window/Window.h"



Label::Label(const sf::String &msg, sf::Uint16 font_size, const sf::String &font_path) {
    setString(msg);
    setCharacterSize(font_size);
    font.loadFromFile(font_path);
    setFont(font);

    def_color = {255, 255, 255, 255};
    drawColor = focus_color = def_color;
}


void Label::set_color(const sf::Color &color) {
    def_color = this->drawColor = color;
}



void Label::setFocus(bool flag) {
    focusFlag = flag;
}


void Label::FocusColor(const sf::Color &color) {
    focus_color = color;
}


void Label::update() {
    drawColor = def_color;
    if(focusFlag /*and focus_color != def_color*/)
        drawColor = focus_color;

    setFillColor(drawColor);
}


void Label::event(sf::Event e) {
    if(e.type == sf::Event::MouseMoved)
        if( e.mouseMove.x >= getPosition().x && e.mouseMove.y >= getPosition().y \
             && e.mouseMove.x <= getPosition().x + getGlobalBounds().width && e.mouseMove.y <= getPosition().y + getGlobalBounds().height)
            focusFlag = true;
        else
            focusFlag = false;
}


void Label::draw(sf::RenderWindow& display) {
    display.draw(*this);
}


Label::~Label() {
    // будет производить автоматическое удаление себя же из общего массива
    Window::erase_object(this);
}