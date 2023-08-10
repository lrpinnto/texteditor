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

    std::vector<std::vector<sf::Vector2f>> getCharacterPosMatrix() const;

    int getMaxNumberOfLines() const {return maxNumberOfLines;};

private:
    void drawLines(sf::RenderWindow &window);
    void drawcursor(sf::RenderWindow &window);

    Content &content;

    sf::View camera;
    sf::Font font;


    // Font size, character height which is always constant
    int fontSize; 
    // Char width from a big character "_". Could be useful
    int charWidth;

    // characterPosMatrix[X][Y]
    // WRITE A BETTER COMMENT EXPLAINING HOW IT WORKS
    std::vector<std::vector<sf::Vector2f>> characterPosMatrix;

    // from 0,0 to +int,+int. Used as argument into characterPosMatrix to find real coordinates
    sf::Vector2f currentCurPos;

    // Number of lines allowed inside the windows according to fontsize. THIS IS THE NUMBER OF COMPLETE LINES WHERE THE WINDOWS DOESNT CUT HALFWAY THROUGH
    int maxNumberOfLines;
};
