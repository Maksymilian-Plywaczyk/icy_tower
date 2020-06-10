#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <ctime>


class Platform:
		public sf::Drawable

{
	
private:

	sf::RectangleShape platform;
	sf::Vector2f size;
	sf::Texture platformTexture;
	
	

	

public:
	Platform(float pos_x, float pos_y, float size_x, float size_y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	const sf::Vector2f getPosition();
	const sf::Vector2f getSize();
	Platform();

};

