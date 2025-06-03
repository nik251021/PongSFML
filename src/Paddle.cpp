#include "Paddle.hpp"

paddle::paddle(const sf::Vector2f& size, const sf::Vector2f& pos) {
    pd.setSize({size});
    pd.setPosition({pos});
    pd.setOrigin({size.x / 2, size.y / 2});
}
void paddle::Move(bool dir, float str) {
    if (dir == 0) {
        pd.setPosition({pd.getPosition().x, pd.getPosition().y - str});
    } else {
        pd.setPosition({pd.getPosition().x, pd.getPosition().y + str});
    }
}

sf::Vector2f paddle::GetPos() {
    return pd.getPosition();
}

void paddle::update(float dt) {

}

void paddle::draw(sf::RenderWindow& window) {
    window.draw(pd);
}