#pragma once
#include "Cancha.h"
#include "Pelota.h"
#include "Arquero.h"
#include "Instrucciones.h"
#include "HUD.h"
#include "Boton.h"

class Juego
{
    Pelota balon;
    Arquero portero;
    Cancha nuevaCancha;
    Instrucciones instrucc;
    Boton BOTON_VOLVER;

public:
    Juego(sf::RenderWindow &window) : portero(balon), BOTON_VOLVER("VOLVER", 1100, 10) {}
    void jugarJuego(sf::RenderWindow &window, HUD &hud)
    {

        actualizarJuego(window, hud);

        drawJuego(window, hud);
    }
    void actualizarJuego(sf::RenderWindow &window, HUD &hud)
    {
        BOTON_VOLVER.drawBoton(window);
        portero.desplazamientoArquero();
        portero.atajada();
        portero.reiniciarDisparo();
        balon.reiniciarDisparo();
        balon.disparo();
        balon.verificarGol();
        hud.Puntaje();
        if (balon.verificarGol())
        {
            hud.anotacion();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            hud.setAnotado(false);
        }
    }
    void drawJuego(sf::RenderWindow &window, HUD &hud)
    {

        nuevaCancha.draw(window);
        portero.draw(window);
        balon.draw(window);
        BOTON_VOLVER.drawBoton(window);
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (BOTON_VOLVER.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            BOTON_VOLVER.setColorBoton(sf::Color::Green);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // HUD.  seleccion = 1;
                cout << "SELECCIONE VOLVER" << endl;
                hud.seleccionVista(0);
            }
        }
        else
        {
            BOTON_VOLVER.setColorBoton(sf::Color::White);
        }
        hud.drawHUD(window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            instrucc.draw(window);
        }
    }
};
