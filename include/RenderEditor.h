#pragma once
#include <SFML/Graphics.hpp>
#include "./Content.h"

int colsOf(sf::String &currentLineText);

class RenderEditor
{

public:
    RenderEditor(const sf::RenderWindow &window,
                 Content &ccontent);

    void draw(sf::RenderWindow &window);

    sf::View getCameraView() { return this->camera; }

    void setCameraBounds(int width, int height);

    void setFontSize(int fontSize);

private:
    void drawLines(sf::RenderWindow &window);

    Content &content;

    sf::View camera;
    sf::Font font;
    int fontSize; // WHERE SHOULD THIS BE SET?
};
