#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 405), "Test Window");
    window.setVerticalSyncEnabled(true);
    sf::Color backgroundColor = sf::Color(21, 29, 45);
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
        }
    }
    window.clear(backgroundColor);
    window.display();
}