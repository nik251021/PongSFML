#include "Game.hpp"
#include <variant>

Game::Game()
    : window(sf::VideoMode({800, 600}), "Pong Game")
    , paddle1({25.f, 250.f}, {50.f, 300.f})
    , paddle2({25.f, 250.f}, {750.f, 300.f})
    , ball(10.f, {400, 0})
{
    window.setFramerateLimit(60);
}

void Game::run() {
    
    while (window.isOpen()) {
        processEvents();

        float dt = clock.restart().asSeconds();

        update(dt);
        render();
    }
}

void Game::processEvents() {
    while (std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            std::cout << "Window was closed" << std::endl;
            window.close();
        }
    }
}


void Game::update(float dt) {
    ball.update(dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        paddle1.Move(true, 300.f * dt);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        paddle1.Move(false, 300.f * dt);
    }

    auto intersection = ball.getBounds().findIntersection(paddle1.getBounds());
    if (intersection.has_value()) {
        ball.bounceX();
    }
    auto intersection2 = ball.getBounds().findIntersection(paddle2.getBounds());
    if (intersection2.has_value()) {
        ball.bounceX();
    }
    ball.checkBounds(window);
    paddle2.SetPos({paddle2.GetPos().x, ball.getPosition().y});

}


void Game::render() {
    window.clear(sf::Color::Black);

    paddle1.draw(window);
    paddle2.draw(window);
    ball.draw(window);

    window.display();
}
