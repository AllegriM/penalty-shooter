#pragma once

#include "SFML/Graphics.hpp"
#include "HUD.h"
#include "Boton.h"

class Menu
{
private:
    sf::Sprite Sprite_Menu;
    sf::Texture Texture_Menu;
    sf::Font Fuente;
    Boton BOTON1;
    Boton BOTON2;
    Boton BOTON3;
    Boton BOTON4;

public:
    // int *getSeleccionPointer() override { return &seleccion; }
    Menu(sf::RenderWindow &window);
    void draw(sf::RenderWindow &, HUD &hud);
    int SelecOpcion(sf::RenderWindow &window, HUD &hud);
    // const int getVista() const { return seleccion; }
};