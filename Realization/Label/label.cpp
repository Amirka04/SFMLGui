#include "label.h"
#include "../Window/Window.h"



Label::Label(const sf::String &msg, const sf::String &font_path, sf::Uint16 font_size) {
    setString(msg);
    setCharacterSize(font_size);
    font.loadFromFile(font_path);
    setFont(font);
}


void Label::update() {}


void Label::event(sf::Event) {}


void Label::draw(sf::RenderWindow& display) {
    display.draw(*this);
}


Label::~Label() {

}