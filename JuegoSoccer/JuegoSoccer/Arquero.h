
#pragma once
#include "SFML/Graphics.hpp"


class Arquero {

    int _velocidad = 5;
    sf::Sprite Sprite_Arquero;
    sf::Texture Texture_Arquero;



public:
    Arquero();
    void movimientoTecladoArquero();
    void getPosicionObjeto();
    void draw(sf::RenderWindow&);


};
 