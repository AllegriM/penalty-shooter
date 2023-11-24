#pragma once
#include "SFML/Graphics.hpp"
#include "HUD.h"
#include "Boton.h"

class Creditos
{
	sf::Font Fuente_creditos;
	sf::Text Texto_creditos;
	Boton BOTON_VOLVER;

public:
	Creditos();
	void draw(sf::RenderWindow &, HUD &hud);
};
