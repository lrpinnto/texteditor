#pragma once

#include <SFML/Graphics.hpp>

class TextEditor {
public:
    TextEditor(sf::RenderWindow& window);

    // Handle a single event (such as a key press or mouse click)
    void handleEvent(const sf::Event& event);

    void handleKeyPressed(const sf::Event::KeyEvent& key);
    void handleMousePressed(const sf::Event::MouseButtonEvent& mouseButton); 
    void handleTextEntered(const sf::Event::TextEvent& text);

    // Handle continuous input (e.g., holding down a key)
    void handleConstantInput();

    // Render the text editor to the window
    void render();

private:
    // Methods to move the cursor in different directions
    void moveCursorUp();
    void moveCursorDown();
    void moveCursorLeft();
    void moveCursorRight();

    // Method to set the cursor position based on mouse click
    void setCursorByMouse(int x, int y);

    // Render the cursor at its current position
    void renderCursor();

    sf::RenderWindow& window; // Reference to the window where the editor is rendered
    sf::Text textContent; // Text object to display the content
    sf::Font font; // Font for displaying text

    int cursorLine; // Line position of the cursor
    int cursorColumn; // Column position of the cursor

    // Add more attributes as needed (e.g., selection, clipboard, etc.)
};