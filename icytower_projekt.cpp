#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include "Platform.h"

int main()
{
     const int videoWidht = 720;
     const int videoHeight = 1000;
    sf::RenderWindow window(sf::VideoMode(videoWidht,videoHeight), "SFML works!");
    Player player(300, 300, 100, 150);
    Platform platform(0,900,videoWidht-10,100);

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
        window.draw(platform);
        window.display();
    }

    return 0;
}