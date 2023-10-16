#pragma once
// #include "Potencia.h"
#include <SFML\Graphics.hpp>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
class Pelota
{
	// Potenciador 
	sf::RectangleShape potenciador;
	sf::RectangleShape cargaPotencia;
	// Pelota
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
	const int BORDE_ARCO_IZQUIERDO = 400;
	const int BORDE_ARCO_DERECHO = 800;
	const int BORDE_ARCO_SUPERIOR = 210 - _sprite.getGlobalBounds().height / 2;
	bool _positionInitial = true;
	float contador;
	bool BanderaCronometro = false;
	float aux = 0.0, maximoPosicionX = 0.0;
	float posicionX, posicionY;
	bool _tiroEfectuado = false;
	char _direccion;
	bool freno = false;

public:
	Pelota();
	//void disparo(float deltatime);
	void cargarPotenciador(float potencia);
	void curvaDisparo(float potencia, float movimientoX);
	void disparo();
	void draw(sf::RenderWindow&);
	void reiniciarDisparo();
	float calcularPotencia();
};