#pragma once

#include <SFML/Graphics.hpp>

class paddle
{
private:
    sf::RectangleShape pd;
public:
    paddle() = default;
    paddle(const sf::Vector2f& size, const sf::Vector2f& pos);
    sf::FloatRect getBounds() const;
    void Move(bool dir, float strenght);
    void SetPos(const sf::Vector2f& pos);
    sf::Vector2f GetPos();
    void update(float dt);
    void draw(sf::RenderWindow& window);
};