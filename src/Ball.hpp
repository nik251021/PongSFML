#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape ball;
    sf::Vector2f vel;
public:
    Ball() = default;
    Ball(float Rad, const sf::Vector2f position);
    void update(float dt);
    void draw(sf::RenderWindow& window);
    void reset(const sf::Vector2f& pos);

    sf::FloatRect getBounds() const;
    void bounceX();
    void bounceY();
    void checkBounds(const sf::RenderWindow& window);
    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& vel);
    sf::Vector2f getPosition() const;
};
