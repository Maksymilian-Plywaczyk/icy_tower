#include "Player.h"

Player::Player(float pos_x, float pos_y, float size_x, float size_y) 
{
	this->size = sf::Vector2f(size_x, size_y);
	this->player.setSize(size);
	this->player.setPosition(pos_x, pos_y);
	
	this->texture.loadFromFile("resources/player.png");
	auto textureSize = this->texture.getSize();

	characterSize = sf::Vector2f( textureSize.x / 11, textureSize.y / 4 );

	this->player.setTexture(&texture);
	this->player.setTextureRect(sf::IntRect(0,0, characterSize.x, characterSize.y));
	
	// TODO
	// zrobic funkcje ktora zwraca nam pozycje poczatkowa intRect
	// auto beginPostion = getPosition(3, 4);
	int a = 4;
	int b = 5;
	int c = 6;
}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(player, states);
}

// 2 sposób rysowania w oknie
//void Player::drawTo(sf::RenderWindow& gameWindow) {
//	gameWindow.draw(player);
//}

void Player::move(float x, float y) {
	
	this->player.move(x, y);
}


void Player::update(const sf::Time& elapsed) {
	auto pobranyCzas = elapsed.asMilliseconds();
	bool leftFace = false;
	//Ograniczyc czas do 1sek
	if (pobranyCzas >= czasOstatniegoPrzesuniecia + czasPrzesunieciaMilisec) { // wchodzi do ifa co 1sek 
		
		if (player.getGlobalBounds().left<=720-player.getSize().x  && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			move(15, 0);
			std::cout << player.getPosition().x<<" "<< player.getPosition().y << std::endl;
			textureRange = sf::Vector2f(3, 6);
			leftFace = false;
			
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getGlobalBounds().left > 0) {
			move(-15, 0);
			textureRange = sf::Vector2f(3, 6);
			leftFace = true;
		
		}
		else {
			textureRange = sf::Vector2f(0, 2);
		}
		currentTexturePos++;


		if (currentTexturePos > textureRange.y) {
			currentTexturePos = textureRange.x;
		}
		if (leftFace)
		{
			
			this->player.setTextureRect(sf::IntRect((currentTexturePos+1) * characterSize.x, 0, -characterSize.x, characterSize.y));
		}
		else {
			this->player.setTextureRect(sf::IntRect((currentTexturePos) * characterSize.x, 0, characterSize.x, characterSize.y));
		}

		


		czasOstatniegoPrzesuniecia = pobranyCzas;
	}
}
