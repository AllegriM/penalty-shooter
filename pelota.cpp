#include "pelota.h"
#include <cmath>

Pelota::Pelota()
{

    _velocity = {10, 10};
    _texture.loadFromFile("pelota.png");
    _sprite.setTexture(_texture);
    //Que la pelota arranque en el centro de la pantalla
    _sprite.setPosition(580, 700);
    
};

void Pelota::update()
{
    // Dependiendo la tecla que toque se le asigna una direccion a la pelota
    _velocity = {0, 0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        _velocity.y = -10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _velocity.y = 10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _velocity.x = -10;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _velocity.x = 10;
    }
    _sprite.move(_velocity);

    if (_sprite.getPosition().x < 0)
    {
        _sprite.setPosition(28, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 1200)
    {
        _sprite.setPosition(1200 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
    }
    if (_sprite.getPosition().y < 0)
    {
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }

    if (_sprite.getPosition().y + _sprite.getGlobalBounds().width > 960)
    {
        _sprite.setPosition(_sprite.getPosition().x, 960 - _sprite.getGlobalBounds().width);
    }
};

void Pelota::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
};

// Dependiendo la tecla que se presione, la pelota se mueve hasta una direccion
// Si apreto 7, la pelota se mueve hacia el arco arriba a la izquierda y no para hasta llegar a el

void Pelota::move(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
    {
        // Ir a la posicion del arco de arriba a la izquierda con una animacion de movimiento
        _sprite.setPosition(350, 150);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
    {
        _sprite.setPosition(350, 350);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
    {
        _sprite.setPosition(800, 150);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
    {
        _sprite.setPosition(800, 350);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
    {
        _sprite.setPosition(570, 150);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
    {
        _sprite.setPosition(570, 350);
    }
};
