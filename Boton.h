#pragma once

#include "SFML/Graphics.hpp"

class Boton
{
private:
    sf::Text textoBoton;
    sf::Font fuenteBoton;

public:
    Boton(std::string texto, float posX, float posY);
    ~Boton();
    void drawBoton(sf::RenderWindow &window) { window.draw(textoBoton); };
    sf::Text getTextoBoton() { return textoBoton; }
    void setColorBoton(const sf::Color &color) { textoBoton.setFillColor(color); }
    const sf::FloatRect getBoundsBoton() const { return textoBoton.getGlobalBounds(); }
};
