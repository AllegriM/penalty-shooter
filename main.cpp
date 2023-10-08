#include <SFML/Graphics.hpp>
#include "pelota.h"
#include "Arco.h"

int main()
{
    //inicializar la ventana
    sf::RenderWindow window(sf::VideoMode(1200, 960), "Penalty24!");
    window.setFramerateLimit(120);
   
    Pelota bocha;
    Arco arco;
   

    // Game loop( update del juego)
    while (window.isOpen())
    {
        //read imput( actualizar los estados de los perifericos de entrada
        //leer la cola de mens

        sf::Event event;
        while (window.pollEvent(event))
        {
            
            
           if (event.type == sf::Event::Closed)
                window.close();
        }

       
        //Update actualiza los estados del juego
        
        bocha.update();

        window.clear();
       
        // Draw
       
        window.draw(arco);
        window.draw(bocha);
      
        

        //display - flip

        window.display();
         

       
    }

    //liberacion del juego

    return 0;
}