#include "Arquero.h"
#include "pelota.h"
#include <stdlib.h>
#include <time.h>

Arquero::Arquero(Pelota &pelota) : pelota(pelota)
{
    Texture_Arquero.loadFromFile("imagenes/nuevoArqueroRedimensionado.png");
    Sprite_Arquero.setTexture(Texture_Arquero);
    Sprite_Arquero.setScale(1.5, 1.5);

    // velocidad de movimiento
    movimientoAleatorio = {0, 0};

    sf::IntRect rect_movimiento_arquero(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);

    Sprite_Arquero.setOrigin(rect_movimiento_arquero.width / 2, rect_movimiento_arquero.height);

    Sprite_Arquero.setPosition(600, 390);
}

bool ataja_o_NoAtaja()
{
    int num, c;
    bool ataja = false;
    srand(time(NULL));

    for (c = 1; c <= 10; c++)
    {
        num = 1 + rand() % (11 - 1);
    }

    if (num <= 6)
    {
        ataja = true;
    }

    return ataja;
}

void Arquero::atajada()
{
    float posicionArqueroX = Sprite_Arquero.getPosition().x;
    float posicionArqueroY = Sprite_Arquero.getPosition().y;
    float posicionPelotaX = pelota.getPositionPelotaX();
    float posicionPelotaY = pelota.getPositionPelotaY();
    char direccion_disparo = pelota.getdireccion();

    if (posicionPelotaX <= 580)
    {
        if (Collision(pelota))
        {
            // cout << "COLISIONA" << endl;
            frame_horizontal = 3;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x, Sprite_Arquero.getPosition().y);
        }
        else
        {
            // cout << "NO COLISIONA" << endl;
        }
    }

    if (posicionPelotaX >= 620)
    {
        if (Collision(pelota))
        {
            // cout << "COLISIONA" << endl;
            frame_horizontal = 10;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x, Sprite_Arquero.getPosition().y);
        }
        else
        {
            // cout << "NO COLISIONA" << endl;
        }
    }

    if (posicionPelotaX > 580 && posicionPelotaX < 620)
    {
        if (Collision(pelota))
        {
            // cout << "COLISIONA" << endl;
            frame_horizontal = 5;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x, Sprite_Arquero.getPosition().y);
        }
        else
        {
            // cout << "NO COLISIONA" << endl;
        }
    }
}

void Arquero::desplazamientoArquero()
{
    sf::IntRect rect_movimiento_arquero(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
    Sprite_Arquero.setOrigin(rect_movimiento_arquero.width / 2, rect_movimiento_arquero.height);

    if (pelota.getTiroEnProceso() && !seDisparo)
    {
        seDisparo = true;
        resultadoDisparo = ataja_o_NoAtaja();
    }

    // cout << "RESULTADO: " << pelota.getTiroEnProceso() << !pelota.getEstadoPelota() << endl;

    if (pelota.getTiroEnProceso() && !pelota.getEstadoPelota())
    {
        if ((pelota.getPositionPelotaX() < 580 && resultadoDisparo) || (!resultadoDisparo && pelota.getPositionPelotaX() > 620))
        {
            Sprite_Arquero.move(-8, 0);
        }
        else if ((pelota.getPositionPelotaX() > 620 && resultadoDisparo) || (!resultadoDisparo && pelota.getPositionPelotaX() < 580))
        {
            Sprite_Arquero.move(8, 0);
        }
        else if (pelota.getPositionPelotaX() == 600 && !resultadoDisparo)
        {
            bool a = ataja_o_NoAtaja();
            cout << a << endl;
            if (a)
            {
                Sprite_Arquero.move(8, 0);
            }
            else
            {
                Sprite_Arquero.move(-8, 0);
            }
        }
    }
    else
    {
        frame_horizontal = 6;
    }

    float positionX = Sprite_Arquero.getPosition().x;

    if (positionX >= 325 && positionX < 385)
    {
        frame_horizontal = 0 + static_cast<int>((positionX - 320) / 65);
    }
    else if (positionX >= 385 && positionX < 580)
    {
        frame_horizontal = 1 + static_cast<int>((positionX - 385) / 65);
    }
    else if (positionX > 620 && positionX < 880)
    {
        frame_horizontal = 9 + static_cast<int>((positionX - 620) / 65);
    }
}

void Arquero::reiniciarDisparo()
{
    if (!pelota.getTiroEnProceso() && pelota.getEstadoPelota() && pelota.getPositionPelotaY() != 730)
    {
        contadorReinicio++;
        if (contadorReinicio >= 120)
        {
            seDisparo = false;
            movimientoAleatorio = {0, 0};
            Sprite_Arquero.setPosition(600, 390);
            contadorReinicio = 0;
        }
    }
}

void Arquero::movimientoTecladoArquero()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, -_velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, _velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(_velocidad, 0);
    }
}

void Arquero::getPosicionObjeto()
{
    sf::IntRect rect_movimiento_arquero(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);

    Sprite_Arquero.setOrigin(rect_movimiento_arquero.width / 2, rect_movimiento_arquero.height);

    if (Sprite_Arquero.getPosition().x < 400 ||
        Sprite_Arquero.getPosition().x + rect_movimiento_arquero.width / 2 > 875)
    {
        movimientoAleatorio.x = -movimientoAleatorio.x;
    }

    if (Sprite_Arquero.getPosition().y < 280 ||
        Sprite_Arquero.getPosition().y + Sprite_Arquero.getGlobalBounds().height > 400)
    {
        movimientoAleatorio.y = -movimientoAleatorio.y;
    }
}

void Arquero::draw(sf::RenderWindow &window)
{
    window.draw(Sprite_Arquero);
}

sf::FloatRect Arquero::getBounds() const
{
    return Sprite_Arquero.getGlobalBounds();
    // sf::FloatRect collisionArea(Sprite_Arquero.getPosition().x - 50, Sprite_Arquero.getPosition().y - 43, 50, 43);
    // return collisionArea;
};