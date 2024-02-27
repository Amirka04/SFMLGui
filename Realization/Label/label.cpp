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


bool Label::isFocus() {
    if( Window::mouse.x >= getPosition().x && Window::mouse.y >= getPosition().y \
        && Window::mouse.x <= getPosition().x + getGlobalBounds().width && Window::mouse.y <= getPosition().y + getGlobalBounds().height)
        return true;
    return false;
}

void Label::FocusColor(const sf::Color &color) {
    focus_color = color;
}



void Label::update() {
    drawColor = def_color;
    if(isFocus() and focus_color != def_color)
        drawColor = focus_color;

    setFillColor(drawColor);
}


void Label::event(sf::Event) {}


void Label::draw(sf::RenderWindow& display) {
    display.draw(*this);
}


Label::~Label() {
    // будет производить автоматическое удаление себя же из общего массива
    Window::erase_object(this);
}