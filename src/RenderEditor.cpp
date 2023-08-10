#include "../include/RenderEditor.h"

RenderEditor::RenderEditor(const sf::RenderWindow &window,
                           Content &ccontent)
    : content{ccontent}, currentCurPos{5,13}
{
    // TEST WITHOUT MONOSPACE. 
    if(!this->font.loadFromFile("../fonts/RobotoMono-VariableFont_wght.ttf"))
        throw std::runtime_error("Font loading failed.");

    this->setFontSize(38);

    // NOTE: this needs to be updated everytime Fontsize changes. Add this later if necessary
    sf::Text longCharacter;
    longCharacter.setFont(this->font);
    longCharacter.setCharacterSize(this->fontSize);
    longCharacter.setString("_");
    this->charWidth = longCharacter.getLocalBounds().width;
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
    this->drawcursor(window);
}

// Draw each lines from getLine()
void RenderEditor::drawLines(sf::RenderWindow &window)
{
    // +1 because static_cast on maxNumberOfLines "does" a floor()

    // RE CHECK THIS CODE
    for (size_t j = 0; j < maxNumberOfLines +1 ; j++) // set to floor instead of using casts?
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

void RenderEditor::drawcursor(sf::RenderWindow &window)
{
    //DEBUGGING
    for (const auto& i : this->characterPosMatrix)
    {
        for (const auto& j : i)
        {
            sf::RectangleShape rect;
            rect.setPosition(j.x,j.y);
            rect.setSize(sf::Vector2f(10, 10));
            rect.setFillColor(sf::Color::Green);
            window.draw(rect);
        }
    }
    

    // TEMPORARY. at() to avoid undefined behavior. Need a better solution?
    if (currentCurPos.x<characterPosMatrix.size() && currentCurPos.y<characterPosMatrix[0].size())
    {
        float posx {this->characterPosMatrix.at(currentCurPos.x).at(currentCurPos.y).x};
        float posy {this->characterPosMatrix.at(currentCurPos.x).at(currentCurPos.y).y};

        sf::RectangleShape rect;
        rect.setPosition(posx,posy);
        rect.setSize(sf::Vector2f(1, fontSize));
        rect.setFillColor(sf::Color::Red);
        window.draw(rect);
    }
}

void RenderEditor::setCameraBounds(int width, int height)
{
    this->camera = sf::View(sf::FloatRect(0, 0, width, height));
}

void RenderEditor::setFontSize(int fontSize) {
    this->fontSize = fontSize;

    updateMaxNumberOfLines();

    updateCursorMatrix();
}

void RenderEditor::updateCursorMatrix()
{
    this->characterPosMatrix.resize(100); //change this to some other number?
    for (auto& i : characterPosMatrix)
    {
        // +1 to allow for not fully drawn lines to display the cursor
        i.resize(maxNumberOfLines+1); 
    }
}

void RenderEditor::updateMaxNumberOfLines()
{
    this->maxNumberOfLines = static_cast<int>(this->camera.getSize().y / fontSize);
}

void RenderEditor::updateCurPos(float x, float y)
{
    this->currentCurPos.x=x;
    this->currentCurPos.y=y;
}

sf::Vector2f RenderEditor::getCurrentCurPos() const
{
    return currentCurPos;
}

std::vector<std::vector<sf::Vector2f>> RenderEditor::getCharacterPosMatrix() const
{
    return this->characterPosMatrix;
}