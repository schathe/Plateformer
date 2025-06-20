#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
    private:
        sf::RectangleShape sprite;
        
        sf::Vector2f velocity;
        float acceleration;
        float maxSpeed;
        float deceleration;

    public:
        Player();
        ~Player() {};

        void inputHandle();
        void update();
        void draw(sf::RenderWindow& window);
};