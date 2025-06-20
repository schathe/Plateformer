#include "Player.hpp"

Player::Player()
{
    sprite.setSize(sf::Vector2f(50.f, 50.f));
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition({100.f, 100.f});
    acceleration = 0.5f;
    maxSpeed = 5.f;
    deceleration = 0.3f;
    velocity.x = 0.f;
}

void Player::inputHandle() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.x -= acceleration;
        if (velocity.x < -maxSpeed)
            velocity.x = -maxSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.x += acceleration;
        if (velocity.x > maxSpeed)
            velocity.x = maxSpeed;
    }
    else {
        if (velocity.x > 0.f) {
            velocity.x -= deceleration;
            if (velocity.x < 0.f) velocity.x = 0.f;
        }
        else if (velocity.x < 0.f) {
            velocity.x += deceleration;
            if (velocity.x > 0.f) velocity.x = 0.f;
        }
    }
}

void Player::update()
{
    sprite.move(velocity);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}