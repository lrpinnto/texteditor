#include "../include/input.h"

void TextEditor::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        handleKeyPressed(event.key);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        handleMousePressed(event.mouseButton);
    } else if (event.type == sf::Event::TextEntered) {
        handleTextEntered(event.text);
    }
    // ... other event types here ...
}

void TextEditor::handleKeyPressed(const sf::Event::KeyEvent& key) {
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

void TextEditor::handleMousePressed(const sf::Event::MouseButtonEvent& mouseButton) {
    // handling mouse button pressed events here...
}

void TextEditor::handleTextEntered(const sf::Event::TextEvent& text) {
    // handling text entered events here...
}
