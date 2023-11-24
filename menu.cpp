#include "menu.h"

Menu::Menu(sf::RenderWindow &window) : BOTON1("JUGAR", 585, 335), BOTON2("ESTADISTICAS", 585, 405),
                                       BOTON3("CREDITOS", 585, 370), BOTON4("SALIR", 585, 440)
{
    Texture_Menu.loadFromFile("imagenes/menu2.png");
    Sprite_Menu.setTexture(Texture_Menu);
    Fuente.loadFromFile("imagenes/dogica.ttf");
}

void Menu::draw(sf::RenderWindow &window, HUD &hud)
{
    window.draw(Sprite_Menu);
    window.draw(BOTON1.getTextoBoton());
    window.draw(BOTON2.getTextoBoton());
    window.draw(BOTON3.getTextoBoton());
    window.draw(BOTON4.getTextoBoton());
    SelecOpcion(window, hud);
}

int Menu::SelecOpcion(sf::RenderWindow &window, HUD &hud)
{

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (BOTON1.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        BOTON1.setColorBoton(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hud.seleccionVista(1);
        }
    }
    else
    {
        BOTON1.setColorBoton(sf::Color::White);
    }

    if (BOTON2.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        BOTON2.setColorBoton(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hud.seleccionVista(2);
        }
        else
        {
            BOTON2.setColorBoton(sf::Color::White);
        }
    }

    if (BOTON3.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        BOTON3.setColorBoton(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hud.seleccionVista(3);
        }
    }
    else
    {
        BOTON3.setColorBoton(sf::Color::White);
    }

    if (BOTON4.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        BOTON4.setColorBoton(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hud.seleccionVista(4);
        }
    }
    else
    {
        BOTON4.setColorBoton(sf::Color::White);
    }
}
