#include "pelota.h"


Pelota::Pelota()
{

    _velocity = { 0,2 };
    _texture.loadFromFile("imagenes/pelota.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(28, 28);
  //  _sprite.setPosition(600, 440);
    _sprite.setPosition(_sprite.getPosition().x, 600);
    _sprite.setPosition(_sprite.getPosition().y, 440);


};





/*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    }*/

    /*
    
    if (_sprite.getPosition().x < 0 ||
        _sprite.getPosition().x + _sprite.getGlobalBounds().width > 800) {
        _velocity.x = -_velocity.x;
    }
    */
 
    /* Movimientos en Y */
    
    // Arriba
   
void Pelota::disparo() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mover = true;
    }
    if (mover == true) {
    
    _sprite.move(_velocity);
    }
    if (_sprite.getPosition().y < 238*potencia) { _velocity.y =0; }
    // Abajo
    if ( _sprite.getPosition().y + _sprite.getGlobalBounds().height > 500 
        ) {
        _velocity.y = -_velocity.y;

    
}

    }

void Pelota::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}