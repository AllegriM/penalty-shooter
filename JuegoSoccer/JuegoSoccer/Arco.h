#pragma once
#include <SFML\Graphics.hpp>

class Arco : public sf::Drawable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;

public:
	Arco();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};