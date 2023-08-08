#include "../include/input.h"

input::input(sf::RenderWindow& wwindow, RenderEditor& eeditorView)
    :window{wwindow} ,editorView{eeditorView}
{

}

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
}

void input::handleTextEntered(const sf::Event::TextEvent& text) {
    // handling text entered events here...
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
