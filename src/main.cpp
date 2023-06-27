#include <SFML/Graphics.hpp>
#include "../include/document.h"

int main()
{
    document doc;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Text Editor");
    window.setVerticalSyncEnabled(true);
    sf::Color backgroundColor = sf::Color(255, 255, 255);
    window.display();

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
                
            }
            
        }
    }
    window.clear(backgroundColor);
    window.display();
}