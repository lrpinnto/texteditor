#pragma once

#include <SFML/Graphics.hpp>
#include "./RenderEditor.h"
#include <iostream>

class input {
public:
    input(sf::RenderWindow&, RenderEditor&);

    // Handle a single event (such as a key press or mouse click)
    void handleEvent(const sf::Event& event);

    void handleKeyPressed(const sf::Event::KeyEvent& key);
    void handleMousePressed(const sf::Event::MouseButtonEvent& mouseButton); 
    void handleTextEntered(const sf::Event::TextEvent& text);

    // Handle continuous input (e.g., holding down a key)
    // void handleConstantInput();

private:
    // Methods to move the cursor in different directions
    void moveCursorUp();
    void moveCursorDown();
    void moveCursorLeft();
    void moveCursorRight();

    // Method to set the cursor position based on mouse click
    //void setCursorByMouse(int x, int y);

    sf::RenderWindow& window; // Reference to the window where the editor is rendered
    sf::Text textContent; // Text object to display the content
    sf::Font font; // Font for displaying text

    int cursorLine; // Line position of the cursor
    int cursorColumn; // Column position of the cursor

    RenderEditor& editorView;

    // Add more attributes as needed (e.g., selection, clipboard, etc.)
};