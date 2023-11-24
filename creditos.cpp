#include "creditos.h"

Creditos::Creditos() : BOTON_VOLVER("VOLVER", 1100, 10)
{
    Fuente_creditos.loadFromFile("imagenes/dogica.ttf");
    Texto_creditos.setFont(Fuente_creditos);

    Texto_creditos.setString("Penalty 24:\n\n \nrealizado por \n \n\nGasty, Marco, Dani y Fede\n\n \nfin del juego");
    Texto_creditos.setOrigin(Texto_creditos.getGlobalBounds().width / 2, Texto_creditos.getGlobalBounds().height / 2);
    Texto_creditos.setPosition(600, 400);

    /*Texture_Cancha.loadFromFile("imagenes/arco.jpeg");
    Sprite_Cancha.setTexture(Texture_Cancha);*/
}

void Creditos::draw(sf::RenderWindow &window, HUD &hud)
{
    window.draw(BOTON_VOLVER.getTextoBoton());
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (BOTON_VOLVER.getTextoBoton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
    {
        BOTON_VOLVER.setColorBoton(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            hud.seleccionVista(0);
        }
    }
    window.draw(Texto_creditos);
}
