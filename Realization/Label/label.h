#ifndef LABEL_H
#define LABEL_H


#include <SFML/Graphics.hpp>
#include "../gui_object.h"



class Label : public Object, public sf::Text{
public:
    // msg, font_file, size_font
    explicit Label(const sf::String &msg, sf::Uint16 font_size = 20, const sf::String &font_path = "fontGUI.ttf");

    // проверка на пересечение курсора и нашего текста
    bool isFocus();

    // установка значения при фокусе
    void FocusColor(const sf::Color&);

    // Деструктор
    ~Label() override;

protected:
    // базовые операции каждого объекта который будет отображаться на экране, будь то контейнер, состояние и т.п
    void update() override;
    void event(sf::Event event) override;
    void draw(sf::RenderWindow&) override;


    sf::Color drawColor;
    sf::Color def_color;
    sf::Color focus_color;

    sf::Font font;
};




#endif