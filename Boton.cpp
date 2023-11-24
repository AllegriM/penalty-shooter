#include "Boton.h"

Boton::Boton(std::string texto, float posX, float posY)
{
    fuenteBoton.loadFromFile("imagenes/dogica.ttf");
    textoBoton.setFont(fuenteBoton);
    textoBoton.setString(texto);
    textoBoton.setOrigin(textoBoton.getGlobalBounds().width / 2, textoBoton.getGlobalBounds().height / 2);
    textoBoton.setPosition(posX, posY);
}

Boton::~Boton() {}
