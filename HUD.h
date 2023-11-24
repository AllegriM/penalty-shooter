#pragma once
#include "pelota.h"

using namespace std;

class HUD
{
public:
	HUD(){};
	void Puntaje();
	void drawHUD(sf::RenderWindow &);
	void anotacion();
	void setAnotado(bool var);
	sf::FloatRect getBotonVolver() { return volver.getGlobalBounds(); }
	void seleccionVista(int selec) { vista = selec; }
	const int getVista() const { return vista; }

private:
	int goles = 0;
	int vista = 0;
	sf::Font font;
	sf::Text text;
	sf::Text volver;
	bool anotado = false;
};
