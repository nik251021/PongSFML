#include "Ball.hpp"

Ball::Ball(float Rad, const sf::Vector2f position) {
    ball.setRadius(Rad);
    ball.setOrigin({ball.getRadius() / 2, ball.getRadius() / 2});
    ball.setPosition({position});
    vel = {300.f, 300.f};
}

sf::FloatRect Ball::getBounds() const {
    return ball.getGlobalBounds();
}

void Ball::update(float dt) {
    ball.move({vel * dt});
}
void Ball::bounceX() {
    vel.x = -vel.x;
}
void Ball::bounceY() {
    vel.y = -vel.y;
}

void Ball::checkBounds(const sf::RenderWindow& window) {
    sf::Vector2f position = ball.getPosition();
    float ballRadius = ball.getRadius();
    sf::Vector2u windowSize = window.getSize();

    if (position.y <= 0 || position.y + 2 * ballRadius >= windowSize.y) {
        vel.y = -vel.y;
    }
}



void Ball::draw(sf::RenderWindow& window) {
    window.draw(ball);
}

sf::Vector2f Ball::getPosition() const {
    return ball.getPosition();
}