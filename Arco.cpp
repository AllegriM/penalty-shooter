#include "Arco.h"

Arco::Arco()
{
	_texture.loadFromFile("arco.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(300, 100);
}



void Arco::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
};