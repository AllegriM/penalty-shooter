#include "pelota.h"

const int ZONAS_DE_POTENCIA = 166;
const int POS_INICIAL_PELOTA_Y = 500;
const int POS_INICIAL_PELOTA_X = 600;

Pelota::Pelota()
{
    // Pelota
    _texture.loadFromFile("imagenes/pelota.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    posicionX = POS_INICIAL_PELOTA_X;
    posicionY = POS_INICIAL_PELOTA_Y;
    _sprite.setPosition(posicionX, posicionY);
    _sprite.setScale(0.5,0.5);
    contador = 0.0;

    // Potenciador
    potenciador.setSize(sf::Vector2f(150.f, 15.f));
    potenciador.setFillColor(sf::Color::Transparent);
    potenciador.setPosition(50, 550);
    potenciador.setOutlineThickness(5);
    potenciador.setOutlineColor(sf::Color::Black);

    // Carga Potencia
    cargaPotencia.setSize(sf::Vector2f(0.f, 15.f));
    cargaPotencia.setPosition(50, 550);
    cargaPotencia.setFillColor(sf::Color::Red);
}

void Pelota::cargarPotenciador(float potencia){
    // TOTAL DEL RECTANGULO 150
    // MAXIMO POTENCIA 3
    // 3 -> 150
    // 2.5 -> x:
    // std::cout << "PORCENTAJE BARRA: " << (potencia * 150) / 3 << std::endl;
    cargaPotencia.setSize(sf::Vector2f((potencia * 150) / 3, 15.f));
    cargaPotencia.setFillColor(sf::Color::Red);
}

float Pelota::calcularPotencia()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        BanderaCronometro = true;
        //sleep_for(milliseconds(50));
        contador++;
    }
        
    BanderaCronometro = false;

    if (contador >= 90) {
        contador = 90;
    }

    if (contador > 0) {
        aux = contador;
    }

    return aux / 30;
}

void Pelota::reiniciarDisparo()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        posicionX = 600;
        posicionY = 500;
        _sprite.setPosition(posicionX, posicionY);

        _positionInitial = true;
        _tiroEfectuado = false;
        _direccion = ' ';
        contador = 0.0;
        aux = 0.0;
        maximoPosicionX = 0;
        freno = false;
    }
}

void Pelota::curvaDisparo(float potencia, float movimientoX){
    // y=−0.008f⋅((posicionX−600.0f) 2)+500.0f => La funcion cuadratica que genera la curva
    // -0.008F curva 
    if(movimientoX < 0 && !freno){
        posicionX += (movimientoX - potencia);
        maximoPosicionX = posicionX;
    }
    if (movimientoX > 0 && !freno){
        posicionX += (movimientoX + potencia);
        maximoPosicionX = posicionX;
    }

    // Posicion de la pelota en Y es mayor a 600 - 1.5 * 200
    if(posicionY > 600 - potencia * ZONAS_DE_POTENCIA){
        posicionY = -0.008f * ((posicionX - POS_INICIAL_PELOTA_X) * (posicionX - POS_INICIAL_PELOTA_X)) + POS_INICIAL_PELOTA_Y;
        posicionX = maximoPosicionX;
        freno = false;
    }else{
        freno = true;
    }
}

void Pelota::disparo(){

    float potencia = calcularPotencia();
    cargarPotenciador(potencia);
    // DISPARO ARRIBA MEDIO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _tiroEfectuado = true;
        _direccion = 'W';
    }
    
    if (_tiroEfectuado && _direccion == 'W'){
        if (posicionY > 600 - potencia * ZONAS_DE_POTENCIA){
            posicionY -= (10 + potencia);
        }
    }

    // DISPARO ARRIBA DERECHA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        _tiroEfectuado = true;
        _direccion = 'E';
    }

    if (_tiroEfectuado && _direccion == 'E'){
        curvaDisparo(potencia, 4);
    }

    // DISPARO ARRIBA IZQUIERDA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        _tiroEfectuado = true;
        _direccion = 'Q';
    }

    if (_tiroEfectuado && _direccion == 'Q'){
        curvaDisparo(potencia, -4);
    }

    // DISPARO ABAJO MEDIO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _tiroEfectuado = true;
        _direccion = 'S';
    }

    if (_tiroEfectuado && _direccion == 'S')
    {
        if(posicionY > 360 && posicionY > 600 - potencia * ZONAS_DE_POTENCIA)
        posicionY -= (10 + potencia);
    }

    // DISPARO ABAJO DERECHA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _tiroEfectuado = true;
        _direccion = 'D';
    }

    if (_tiroEfectuado && _direccion == 'D')
    {
        curvaDisparo(potencia, 4);
    }

    // DISPARO ABAJO IZQUIERDA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _tiroEfectuado = true;
        _direccion = 'A';
    }

    if (_tiroEfectuado && _direccion == 'A')
    {
        curvaDisparo(potencia, -4);
    }
}

void Pelota::draw(sf::RenderWindow& window)
{
    _sprite.setPosition(posicionX, posicionY);
    window.draw(potenciador);
    window.draw(cargaPotencia);
    window.draw(_sprite);
}


