#include "pelota.h"


Pelota::Pelota()
{

    _velocity = { 10,10 };
    _texture.loadFromFile("./imagenes/pelota.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(0, 0);
    _sprite.setPosition(0, 0);
};


void Pelota::update()
{
    _velocity = { 0, 0 };

    // Restablece la velocidad de la pelota.


    // Verifica si se presionó la barra espaciadora para realizar el disparo.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        // Establece la velocidad del disparo (ajusta la velocidad según tus necesidades).
        float velocidadDisparo = 10.0f;

        // Define la posición del destino (arco) donde quieres que llegue la pelota.
        sf::Vector2f destino(800, 480);  // Cambia las coordenadas según tu juego.

        // Calcula la dirección desde la posición actual de la pelota hacia el destino.
        sf::Vector2f direccion = destino - _sprite.getPosition();

        // Normaliza la dirección para mantener la misma velocidad en todas las distancias.
        float longitud = sqrt(direccion.x * direccion.x + direccion.y * direccion.y);
        if (longitud != 0)
        {
            direccion /= longitud;
        }

        // Asigna la velocidad multiplicando la dirección por la velocidad deseada.
        _velocity = direccion * velocidadDisparo;

        /*  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
              _velocity.y= -10;
          }


          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
              _velocity.y = 10;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
              _velocity.x =-10;
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
              _velocity.x = 10;
          }
          _sprite.move(_velocity);



          if (_sprite.getPosition().x < 0) {
              _sprite.setPosition(28, _sprite.getPosition().y);

          }
          if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 1200) {
              _sprite.setPosition(1200 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);

          }
          if (_sprite.getPosition().y < 0) {
              _sprite.setPosition(_sprite.getPosition().x, 0);
          }

          if (_sprite.getPosition().y + _sprite.getGlobalBounds().width > 960) {
              _sprite.setPosition(_sprite.getPosition().x,960 - _sprite.getGlobalBounds().width);
          }*/
    };
}
/*
    void Pelota::draw(sf::RenderTarget & target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    };

    */

void Pelota::draw(sf::RenderWindow& window)
{
    window.draw(_sprite);
}