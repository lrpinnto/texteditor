#include "../include/RenderEditor.h"

RenderEditor::RenderEditor(const sf::RenderWindow &window,
                           Content &ccontent)
    : content{ccontent}
{
    // TEST WITHOUT MONOSPACE. 
    if(!this->font.loadFromFile("../fonts/RobotoMono-VariableFont_wght.ttf"))
        throw std::runtime_error("Font loading failed.");

    this->setFontSize(38);

    // big matrix for testing purposes
    characterPosMatrix.resize(100);
    for (auto& i : characterPosMatrix)
    {
        i.resize(100); // 100 x 100 matrix. huge. doesnt need to be this big
    }
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
    this->drawrectangles(window);
}

// Draw each lines from getLine()
void RenderEditor::drawLines(sf::RenderWindow &window)
{
    // RE CHECK THIS CODE
    for (size_t j = 0; j < static_cast<int>(this->camera.getSize().y / fontSize); j++) // set to floor instead of using casts?
    {
        sf::Text lineText;
        lineText.setFillColor(sf::Color::Black);
        lineText.setFont(font);

        // TEMPORARY. IF IT TRIES TO READ FOR AN INVALID LINE, IT HANDLES THE ERROR AND BREAKS THE FOR CYCLE

        try
        { 
            lineText.setString(content.getLine(j));
        } catch (std::runtime_error)
        {
            break;
        }

        lineText.setCharacterSize(fontSize);
        lineText.setPosition(0, j*fontSize);

        // FOR CURSOR
        for (size_t x = 0; x < lineText.getString().getSize(); x++)
        {
            this->characterPosMatrix[x][j] = lineText.findCharacterPos(x);
        }
        
        window.draw(lineText);
    }
}

void RenderEditor::drawrectangles(sf::RenderWindow &window)
{
    for (size_t j = 0; j < 40 ; j++) // 40 is arbitrary. 
    {
        for (size_t i = 0; i < 40; i++)
        {
            sf::RectangleShape rect;
            rect.setPosition(this->characterPosMatrix[i][j].x,this->characterPosMatrix[i][j].y);
            rect.setSize(sf::Vector2f(1, fontSize));
            rect.setFillColor(sf::Color::Red);
            window.draw(rect);
        }
    }
}

void RenderEditor::setCameraBounds(int width, int height)
{
    this->camera = sf::View(sf::FloatRect(0, 0, width, height));
}

void RenderEditor::setFontSize(int fontSize) {
    this->fontSize = fontSize;
}

void RenderEditor::updateCursorMatrix()
{
    // Do I really need this? Cant I just use a big matrix?
    //characterPosMatrix.resize(); 
}