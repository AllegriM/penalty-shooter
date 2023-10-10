#pragma once
#include <SFML/Graphics.hpp>

class Pelota: public sf::Drawable 
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;

public:
	Pelota();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	// Dependiendo la tecla que se presione, la pelota se mueve a una direccion
	// 7: arriba izquierda, 1: abajo izquierda, 9: arriba derecha, 3: abajo derecha, 8: arriba centro, 2: abajo centro
	void move();
	
};   
