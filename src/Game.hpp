#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

#include <iostream>

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    paddle paddle1;
    paddle paddle2;
};
