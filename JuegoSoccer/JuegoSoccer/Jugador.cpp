#include "Jugador.h"
Jugador::Jugador()
{
    _desplazamientoImagen = 80;
    Rect_movimientosPateador= sf::IntRect(_desplazamientoImagen*2, _desplazamientoImagen, _desplazamientoImagen, _desplazamientoImagen);
    Texture_Pateador.loadFromFile("./imagenes/elpateador.png");
    Spriter_Pateador.setTexture(Texture_Pateador);
    Spriter_Pateador.setTextureRect(Rect_movimientosPateador);
    _velocidad = 1;
    _precision = 1;
    _edad = 30;
    _goles = 0;

    
}

/*
    char nombre[] = "Daniel";
    char apellido[] = "Guillen";
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);*/
/*
void Jugador::setNombre(const char *n)
{
	strcpy(_nombre, n);
}
void Jugador::setApellido(const char *a)
{
	strcpy(_apellido, a);
}
void Jugador::draw(sf::RenderWindow& window)
{
	window.draw(Sprite_Jugador);
}

*/
void Jugador::movimientoDelPateador() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Spriter_Pateador.move(0, -_velocidad);
        Rect_movimientosPateador = sf::IntRect(_desplazamientoImagen+80, _desplazamientoImagen+80, _desplazamientoImagen * 3, _desplazamientoImagen * 3);
        Spriter_Pateador.setTextureRect(Rect_movimientosPateador);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Spriter_Pateador.move(0, _velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Spriter_Pateador.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Spriter_Pateador.move(_velocidad, 0);
    }
}
void Jugador::getPosicionPateador()
{
    
    if (Spriter_Pateador.getPosition().x < 100) {
        Spriter_Pateador.setPosition(100, Spriter_Pateador.getPosition().y);
    }
    if (Spriter_Pateador.getPosition().x > 740) {
        Spriter_Pateador.setPosition(740, Spriter_Pateador.getPosition().y);
    }

    if (Spriter_Pateador.getPosition().y < 400) {
        Spriter_Pateador.setPosition(Spriter_Pateador.getPosition().x, 400);
    }

    if (Spriter_Pateador.getPosition().y > 306) {
        Spriter_Pateador.setPosition(Spriter_Pateador.getPosition().x, 306);
    }
}
void Jugador::draw(sf::RenderWindow& window)
{
    window.draw(Spriter_Pateador);
}