#pragma once
#include <SFML/Graphics.hpp>

class Pelota: public sf::Drawable 
{

	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;

public:
	Pelota();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};   
