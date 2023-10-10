#pragma once
#include <SFML/Graphics.hpp>

class Instrucciones : public sf::Drawable{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
    Instrucciones();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
};