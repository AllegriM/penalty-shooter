#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "pelota.h"

class Arquero : public Collisionable
{
    int _velocidad = 5;
    sf::Sprite Sprite_Arquero;
    sf::Texture Texture_Arquero;
    sf::Vector2f movimientoAleatorio;
    float origen_x = 600, origen_y = 290;
    // sf::Vector2f direccionMovimientoArquero;
    const int POS_INICIAL_ARQUERO_Y = 290;
    const int POS_INICIAL_ARQUERO_X = 600;
    float posicionArqX;
    float posicionArqY;

    //=============== FRAME ARQUERO ================== //
    int frame_horizontal = 6;
    int frame_vertical = 0;
    int frame_ancho = 100; // Ancho de cada frame
    int frame_alto = 85;   // Alto de cada frame
    sf::IntRect rect_movimiento_arquero;
    int auxContador = 0, contadorReinicio = 0;
    bool seDisparo = false;
    bool resultadoDisparo;
    Pelota &pelota;

public:
    Arquero(Pelota &pelota);
    void desplazamientoArquero();
    void movimientoTecladoArquero();
    void getPosicionObjeto();
    void draw(sf::RenderWindow &);
    sf::FloatRect getBounds() const override;
    void reiniciarDisparo();
    void atajada();
};