#include <SFML/Graphics.hpp>
#include "Player.h"
#include <iostream>
#include "Platform.h"
#include <vector>
#include <list>
//TODO 

//1.Platforms
int main()
{
    const int videoWidht = 720;
    const int videoHeight = 1000;
    sf::RenderWindow window(sf::VideoMode(videoWidht,videoHeight), "SFML works!");
    Player player(videoWidht/2, 500, 100, 150);
    Platform platform(0,900,videoWidht,100);
  
   
    std::list<Platform*>platforms;
    platforms.push_back(new Platform(0, 900, videoWidht, 100));
   

    double pozTworz = 900;
    const int odleglosc = 200;

    sf::Clock timer;
    
    while (window.isOpen())
    {
    
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update
        player.update(timer.getElapsedTime());
        for (auto p : platforms)
        {
            player.collision(p->getPosition(), p->getSize());
                   
        }
        
        
        
       while (pozTworz > 0) {
            pozTworz -= odleglosc;

            platforms.emplace_back(new Platform(rand()%900, pozTworz,videoWidht/3, 50)); // moves
         

        }
        
       //rysowanie
        window.clear();
        for (auto& p : platforms)
        {
            window.draw(*p);
        }
       
        window.draw(player);
        window.display();
     
        

    }

    return 0;
}