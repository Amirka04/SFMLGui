#ifndef LABEL_H
#define LABEL_H


#include <SFML/Graphics.hpp>
#include "../gui_object.h"




class Label : public Object, public sf::Text{
public:
    // msg, font_file, size_font
    explicit Label(const sf::String &msg, const sf::String &font_path = "fontGUI.ttf", sf::Uint16 font_size = 20);
    ~Label() override;
protected:
    void update() override;
    void event(sf::Event event) override;
    void draw(sf::RenderWindow&) override;

    sf::Font font;
};



#endif