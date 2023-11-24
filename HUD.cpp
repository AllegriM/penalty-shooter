#include "HUD.h"
#include <iostream>

using namespace std;

void HUD::Puntaje()
{
    font.loadFromFile("imagenes/dogica.ttf");
    text.setFont(font);

    text.setString("Goles: " + to_string(goles));
}

void HUD::drawHUD(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(volver);

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (volver.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        volver.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // El rat�n est� sobre el bot�n
        }
    }
    else
    {
        // El rat�n no est� sobre el bot�n
        volver.setFillColor(sf::Color::White);
    }
}

void HUD::anotacion()
{
    if (!anotado)
    {
        goles++;
        anotado = true;
    }
}

void HUD::setAnotado(bool var) { anotado = var; }
