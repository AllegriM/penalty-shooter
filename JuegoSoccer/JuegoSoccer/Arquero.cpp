
#include "Arquero.h"
Arquero::Arquero() {
    Texture_Arquero.loadFromFile("./imagenes/Arquero50.png");
    Sprite_Arquero.setTexture(Texture_Arquero);
    

}



void Arquero::movimientoTecladoArquero() {
  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Sprite_Arquero.move(0, -_velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Sprite_Arquero.move(0, _velocidad);
    }
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Sprite_Arquero.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Sprite_Arquero.move(_velocidad, 0);
    }
}
void Arquero::getPosicionObjeto() 
{

    /*Movimientos en X*/
    if (Sprite_Arquero.getPosition().x < 400) {
        Sprite_Arquero.setPosition(400, Sprite_Arquero.getPosition().y);
    }
    if (Sprite_Arquero.getPosition().x > 740) {
        Sprite_Arquero.setPosition(740, Sprite_Arquero.getPosition().y);
    }
    
    if (Sprite_Arquero.getPosition().y < 290) {
        Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().x, 290);

    }
    
    if (Sprite_Arquero.getPosition().y > 306) {
        Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().x, 306);

    }
}

void Arquero::draw(sf::RenderWindow& window)
{
    window.draw(Sprite_Arquero);
}

