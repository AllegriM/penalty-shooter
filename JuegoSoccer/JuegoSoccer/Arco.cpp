#include "Arco.h"


Arco::Arco()
{
	_texture.loadFromFile("./imagenes/arco.png");
	_sprite.setTexture(_texture);
	_sprite.setScale(0.7, 0.6);
	_sprite.setOrigin(300, 150);
	_sprite.setPosition(600, 200);
}



void Arco::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
};