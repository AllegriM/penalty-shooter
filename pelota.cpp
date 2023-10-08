#include "pelota.h"

Pelota::Pelota()
{

    _velocity = {10, 10};
    _texture.loadFromFile("pelota.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(28, 28);
};

void Pelota::update()
{
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
