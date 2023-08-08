#pragma once
#include <SFML/Graphics.hpp>
#include "./Content.h"
#include <stdexcept>

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

    void updateCursorMatrix();

    void updateMaxNumberOfLines();

    void updateCurPos(float x, float y);

    sf::Vector2f getCurrentCurPos() const;

private:
    void drawLines(sf::RenderWindow &window);
    void drawcursor(sf::RenderWindow &window);

    Content &content;

    sf::View camera;
    sf::Font font;
    int fontSize; // WHERE SHOULD THIS BE SET?
    int charWidth;

    // characterPosMatrix[X][Y]
    std::vector<std::vector<sf::Vector2f>> characterPosMatrix;

    sf::Vector2f currentCurPos;

    // Number of lines allowed inside the windows according to fontsize. 
    int maxNumberOfLines;
};
