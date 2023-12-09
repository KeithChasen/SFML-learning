#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GAME KEITH");

    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color(200, 200, 0));

    sf::RectangleShape rect(sf::Vector2f(120.f, 50.f));
    

    // set frame rate limit
    // to run app at a given frame rate 
    // instead of monitor's frequency
    window.setFramerateLimit(60);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.draw(rect);

        window.display();
    }

    return 0;
}