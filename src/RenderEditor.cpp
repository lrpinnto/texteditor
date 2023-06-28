#include "../include/RenderEditor.h"

RenderEditor::RenderEditor(const sf::RenderWindow &window,
                           Content &ccontent)
    : content{ccontent}
{
    this->font.loadFromFile("../fonts/Roboto-Light.ttf");
}

// Draw everything, for cycle for line numbers
void RenderEditor::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect;
    rect.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::Black);
    window.draw(rect);
    this->drawLines(window);
}

// Draw each lines from getLine()
void RenderEditor::drawLines(sf::RenderWindow &window)
{
    sf::Text lineText;
    lineText.setFillColor(sf::Color::White);
    lineText.setFont(font);
    lineText.setString("TEST TEXT");
    lineText.setCharacterSize(25);
    lineText.setPosition(0, 0);

    window.draw(lineText);
}

void RenderEditor::setCameraBounds(int width, int height)
{
    this->camera = sf::View(sf::FloatRect(-50, 0, width, height));
}