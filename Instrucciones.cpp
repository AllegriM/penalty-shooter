#include "Instrucciones.h"

Instrucciones::Instrucciones(){
    _texture.loadFromFile("instrucciones.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(600, 480);
}

void Instrucciones::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
};