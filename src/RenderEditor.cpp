#include "../include/RenderEditor.h"

RenderEditor::RenderEditor(const sf::RenderWindow &window,
                           Content &ccontent)
    : content{ccontent}
{
    // Is relative path good enough for all purposes?
    this->font.loadFromFile("../fonts/Roboto-Light.ttf");

    this->setFontSize(18);
}

// Draw everything, for cycle for line numbers
void RenderEditor::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect;
    rect.setPosition(window.getSize().x-10,window.getSize().y-10);
    rect.setSize(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Black);
    window.draw(rect);
    this->drawLines(window);
}

// Draw each lines from getLine()
void RenderEditor::drawLines(sf::RenderWindow &window)
{
    // RE CHECK THIS CODE
    for (size_t i = 0; i < static_cast<int>(this->camera.getSize().y / fontSize); i++) // set to floor instead of using casts?
    {
        sf::Text lineText;
        lineText.setFillColor(sf::Color::Black);
        lineText.setFont(font);

        // TEMPORARY. IF IT TRIES TO READ FOR AN INVALID LINE, IT HANDLES THE ERROR AND BREAKS THE FOR CYCLE

        try
        { 
            lineText.setString(content.getLine(i));
        } catch (std::runtime_error)
        {
            break;
        }

        lineText.setCharacterSize(fontSize);
        lineText.setPosition(0, i*fontSize);

        window.draw(lineText);
    }
}

void RenderEditor::setCameraBounds(int width, int height)
{
    this->camera = sf::View(sf::FloatRect(0, 0, width, height));
}

void RenderEditor::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}