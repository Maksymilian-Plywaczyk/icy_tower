#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(720, 720), "SFML works!");
    Player player(300, 300, 100, 150);

    sf::Clock timer;
    
    while (window.isOpen())
    {
    
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //std::cout << timer.getElapsedTime().asMilliseconds() << std::endl;
        player.update(timer.getElapsedTime());
        

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}