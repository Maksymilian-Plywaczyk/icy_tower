#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : 
	public sf::Drawable
{
private:
	sf::RectangleShape player;
	sf::Vector2f size;
	sf::Texture texture;
	double czasOstatniegoPrzesuniecia = 0;
	double czasPrzesunieciaMilisec = 100;
	sf::Vector2f textureRange = {0, 0};
	unsigned int currentTexturePos = 0;
	sf::Vector2f characterSize;
	

public:
	Player(float pos_x, float pos_y, float size_x, float size_y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//void drawTo(sf::RenderWindow& gameWindow);
	void move(float x, float y);
	void update(const sf::Time& elapsed);
	
	 
};



