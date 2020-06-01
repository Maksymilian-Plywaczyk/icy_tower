#include "Platform.h"

Platform::Platform(float pos_x, float pos_y, float size_x, float size_y)
{
	this->size = sf::Vector2f (size_x, size_y);
	this->platform.setSize(size);
	this->platform.setPosition(pos_x, pos_y);

	this->platformTexture.loadFromFile("resources/platform1.png");
	auto textureSize = this->platformTexture.getSize();

	

	this->platform.setTexture(&platformTexture);
	
	this->platform.setOutlineColor(sf::Color::Red);
	this->platform.setOutlineThickness(2);



}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(platform,states);

}

