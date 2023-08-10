#include "../include/input.h"

input::input(sf::RenderWindow& wwindow, RenderEditor& eeditorView, Content& contentt)
    :window{wwindow} ,editorView{eeditorView}, content{contentt}
{ }

void input::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        handleKeyPressed(event.key);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        handleMousePressed(event.mouseButton);
    } else if (event.type == sf::Event::TextEntered) {
        handleTextEntered(event.text);
    }
    // ... other event types here ...
}

void input::handleKeyPressed(const sf::Event::KeyEvent& key) {
    // handling key pressed events here...

    if (key.code == sf::Keyboard::Up) {
            moveCursorUp(); 
            return;
        }
        if (key.code == sf::Keyboard::Down) {
            moveCursorDown(); 
            return;
        }
        if (key.code == sf::Keyboard::Left) {
            moveCursorLeft(); 
            return;
        }
        if (key.code == sf::Keyboard::Right) {
            moveCursorRight(); 
            return;
        }

        // Handle other key presses here...
}

void input::handleMousePressed(const sf::Event::MouseButtonEvent& mouseButton) {
    // handling mouse button pressed events here...

    auto mouseposx = mouseButton.x;
    auto mouseposy = mouseButton.y;
    sf::Vector2f mousepos {static_cast<float>(mouseposx),static_cast<float>(mouseposy)};

    const auto& CharacterPosMatrix = this->editorView.getCharacterPosMatrix();

    for (size_t indexX = 0 ; indexX < CharacterPosMatrix.size() ; indexX++)
    {
        const auto& yRow {CharacterPosMatrix[indexX]};
    
        auto it = std::upper_bound(yRow.begin(), yRow.end(), mousepos,
            // No '<' operand defined for sf::Vector2f. Need to define it
            [](const sf::Vector2f& lhs, const sf::Vector2f& rhs) {
                return lhs.x < rhs.x && lhs.y < rhs.y;
            }
        );
        if (it!=yRow.end())
        {
            size_t indexY = std::distance(yRow.begin(), it);
            // Outputs the nearest "square" that is superior in both the x and y values to mousepos
            std::cerr<<indexX<<" "<<indexY<<std::endl;
            this->editorView.updateCurPos(indexX-1, indexY-1);
            break; //found it
        }
    }

    /*auto mousepos_text = window.mapPixelToCoords(mousepos);

    std::pair<int, int> docCoords = textView.getDocumentCoords(mousepos_text.x, mousepos_text.y);
    this->editorContent.createNewSelection(docCoords.first, docCoords.second);

    this->mouseDown = true;*/
}

void input::handleTextEntered(const sf::Event::TextEvent& text) {
    // handling text entered events here...

    char ch = static_cast<char>(text.unicode);
    this->content.addTextToPos(ch, this->editorView.getCurrentCurPos().x, this->editorView.getCurrentCurPos().y);
    this->editorView.updateCurPos(this->editorView.getCurrentCurPos().x+1, this->editorView.getCurrentCurPos().y);
}

void input::moveCursorUp()
{
    this->editorView.updateCurPos(editorView.getCurrentCurPos().x,editorView.getCurrentCurPos().y-1);
}
void input::moveCursorDown()
{
    this->editorView.updateCurPos(editorView.getCurrentCurPos().x,editorView.getCurrentCurPos().y+1);
}
void input::moveCursorLeft()
{
    this->editorView.updateCurPos(editorView.getCurrentCurPos().x-1,editorView.getCurrentCurPos().y);
}
void input::moveCursorRight()
{
    this->editorView.updateCurPos(editorView.getCurrentCurPos().x+1,editorView.getCurrentCurPos().y);
}
