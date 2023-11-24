#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "creditos.h"
#include "juego.h"

using namespace std;
int main()
{
    // resolucion
    sf::RenderWindow window(sf::VideoMode(1200, 800), "FullBall Soccer");
    window.setFramerateLimit(60);

    HUD hud;
    Menu menu(window);
    Juego juego(window);
    Creditos credito;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        switch (hud.getVista())
        {
        case 0:
        {
            menu.draw(window, hud);
        }
        break;
        case 1:
        {
            cout << "ESTOY EN CASE 1" << endl;
            juego.jugarJuego(window, hud);
        }
        break;
        case 2:
            break;
        case 3:
        {
            cout << "ESTOY EN CASE 2" << endl;
            credito.draw(window, hud);
        }
        break;
        case 4:
        {
            exit(0);
        }

        break;
        default:
            break;
        }

        window.display();
    };

    return 0;
}