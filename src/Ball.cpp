#include "Ball.hpp"

Ball::Ball(float Rad, const sf::Vector2f position) {
    ball.setRadius(Rad);
    ball.setPosition({position});
}