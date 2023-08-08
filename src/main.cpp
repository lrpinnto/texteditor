#include <SFML/Graphics.hpp>
#include "../include/document.h"
#include "../include/RenderEditor.h"

int main()
{
    document doc;

    doc.init("testdocument.txt");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Text Editor");
    window.setVerticalSyncEnabled(true);
    sf::Color backgroundColor = sf::Color::White;
    window.display();

    Content content{doc};

    RenderEditor editorView{window, content};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                editorView.setCameraBounds(event.size.width, event.size.height);
                editorView.updateMaxNumberOfLines();
                editorView.updateCursorMatrix();
            }
        }
        window.clear(backgroundColor);
        window.setView(editorView.getCameraView());
        editorView.draw(window);
        window.display();
    }
}