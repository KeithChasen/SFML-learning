#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class CircleWrapper
{
    std::string name;

    int m_x;
    int m_y;

    int m_sx;
    int m_sy;

    int m_R;
    int m_G;
    int m_B;

    int m_r;

public:

};

class RectWrapper
{
    std::string name;

    int m_x;
    int m_y;

    int m_sx;
    int m_sy;

    int m_R;
    int m_G;
    int m_B;

    int m_w;
    int m_h;

public:

};

class ShapeKeeper
{
    std::vector<CircleWrapper> circles;
    std::vector<RectWrapper> rects;

    int windowWidth;
    int windowHeight;

    std::string fontPath;
    int fontSize;

    int fontR;
    int fontG;
    int fontB;

    void setFont(
        const std::string& path, 
        const int size, 
        const int R, 
        const int G, 
        const int B
    ) 
    {
        fontPath = path;
        fontSize = size;

        fontR = R;
        fontG = G;
        fontB = B;
    }

    void setWindowSettings(
        const int W, 
        const int H
    )
    {
        windowWidth = W;
        windowHeight = H;
    }

    void setRect(
        std:: string name, 
        int x, 
        int y, 
        int sx, 
        int sy, 
        int R, 
        int G, 
        int B, 
        int w, 
        int h
    )
    {

    }

    void setCircle(
        std:: string name, 
        int x, 
        int y, 
        int sx, 
        int sy, 
        int R, 
        int G, 
        int B, 
        int r
    )
    {

    }


    void readShapesFromFile(const std::string& filename)
    {
        //input file stream
        std::ifstream fileStream(filename);

    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GAME KEITH");

    sf::Font font;
    if (!font.loadFromFile("fonts/Aaargh.ttf")) 
    {
        std::cerr << "Could not load the font" << std::endl;
        exit(-1);
    }

    sf::Text text;
    
    text.setFont(font);
    
    text.setString("Some text");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(300, 300);

    float circleSpeedX = 3.0f;
    float circleSpeedY = 3.0f;

    sf::CircleShape circle(30.f);
    circle.setFillColor(sf::Color(200, 200, 0));

    float rectSpeedX = 4.0f;
    float rectSpeedY = 4.0f;

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

        circle.setPosition(
            circle.getPosition().x + circleSpeedX, 
            circle.getPosition().y + circleSpeedY
        );

        rect.setPosition(
            rect.getPosition().x + rectSpeedX,
            rect.getPosition().y + rectSpeedY
        );

        if (
            circle.getPosition().x < 0 || 
            circle.getPosition().x + (circle.getRadius()) * 2 > window.getSize().x
            ) 
        {
            circleSpeedX = -circleSpeedX;
        }

        if (
            rect.getPosition().x < 0 || 
            rect.getPosition().x + rect.getSize().x > window.getSize().x
            ) 
        {
            rectSpeedX = -rectSpeedX;
        }

        if (
            circle.getPosition().y < 0 || 
            circle.getPosition().y + (circle.getRadius()) * 2 > window.getSize().y
        ) 
        {
            circleSpeedY = -circleSpeedY;
        }

        if (
            rect.getPosition().y < 0 || 
            rect.getPosition().y + rect.getSize().y > window.getSize().y
        ) 
        {
            rectSpeedY = -rectSpeedY;
        }

        window.clear(sf::Color::Black);

        window.draw(circle);

        window.draw(text);

        window.draw(rect);

        window.display();
    }

    return 0;
}