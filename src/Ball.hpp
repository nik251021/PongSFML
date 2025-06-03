#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape ball;
    int dir;
public:
    Ball() = default;
    Ball(float Rad, const sf::Vector2f position);
    void ChangeDir();
    void update();
    void draw();
};
