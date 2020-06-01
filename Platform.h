#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Platform:
		public sf::Drawable
{
private:
	sf::RectangleShape platform;
	sf::Vector2f size;
	sf::Texture platformTexture;
	sf::Vector2f platformSize;
public:
	Platform(float pos_x, float pos_y, float size_x, float size_y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

};

