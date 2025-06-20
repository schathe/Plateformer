#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Platformer");
    window.setFramerateLimit(60);

    Player player;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        player.inputHandle();
        player.update();

        window.clear();

        player.draw(window);

        window.display();
    }

    return 0;
}