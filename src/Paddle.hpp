#pragma once

#include <SFML/Graphics.hpp>

class paddle
{
private:
    sf::RectangleShape pd;
public:
    paddle() = default;
    paddle(const sf::Vector2f& size, const sf::Vector2f& pos);
    void Move(bool dir, float strenght);
    sf::Vector2f GetPos();
    void update(float dt);
    void draw(sf::RenderWindow& window);
};