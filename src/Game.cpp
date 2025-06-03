#include "Game.hpp"
#include <variant>

Game::Game()
    : window(sf::VideoMode({800, 600}), "Pong Game")
    , paddle1({25.f, 250.f}, {50.f, 300.f})
    , paddle2({25.f, 250.f}, {750.f, 300.f})
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        paddle1.Move(true, 300.f * dt);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        paddle1.Move(false, 300.f * dt);
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    paddle1.draw(window);
    paddle2.draw(window);

    window.display();
}
