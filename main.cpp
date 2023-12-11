#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class CircleWrapper
{
    sf::Text m_name;

    float m_x;
    float m_y;

    float m_sx;
    float m_sy;

    int m_R;
    int m_G;
    int m_B;

    float m_r;

    sf::CircleShape circle;

public:
    CircleWrapper(
            std::string name,
            float x, 
            float y, 
            float sx, 
            float sy, 
            int R, 
            int G, 
            int B, 
            float r, 
            sf::Font font, 
            int fontSize,
            int fR,
            int fG,
            int fB
        )
        : m_sx(sx)
        , m_sy(sy)
    {
        circle.setRadius(r);

        circle.setPosition(x, y);
        circle.setFillColor(sf::Color(R, G, B));

        // set font and text
        //! todo: learn inheritance in C++ and refactor
        // m_name.setFont(font);
        // m_name.setString(name);
        // m_name.setCharacterSize(fontSize);
        // sf::Color color(fR, fG, fB);
        // m_name.setFillColor(color);
        // m_name.setPosition(x, y);
    }

    sf::CircleShape& getCircle()
    {
        return circle;
    }

    //! inheritance
    float getSpeedX() 
    {
        return m_sx;
    }

    float getSpeedY() 
    {
        return m_sy;
    }

    void setSpeedX(float sx) 
    {
        m_sx = sx;
    }

    void setSpeedY(float sy)
    {
        m_sy = sy;
    }
    //! inheritance
};

class RectWrapper
{
    sf::Text m_name;

    float m_x;
    float m_y;

    float m_sx;
    float m_sy;

    int m_R;
    int m_G;
    int m_B;

    float m_w;
    float m_h;

    sf::RectangleShape rect;

public:
    RectWrapper(
            std::string name, 
            float x, 
            float y, 
            float sx, 
            float sy, 
            int R, 
            int G, 
            int B, 
            float w, 
            float h, 
            sf::Font font, 
            int fontSize,
            int fR,
            int fG,
            int fB
    )
        : m_x(x)
        , m_y(y)
        , m_sx(sx)
        , m_sy(sy)
        , m_R(R)
        , m_G(G)
        , m_B(B)
    {
        rect.setSize(sf::Vector2f(w, h));

        rect.setPosition(x, y);
        rect.setFillColor(sf::Color(R, G, B));

        // set font and text

        //! todo: learn inheritance in C++ and refactor
        // m_name.setFont(font);
        // m_name.setString(name);
        // m_name.setCharacterSize(fontSize);
        // sf::Color color(fR, fG, fB);
        // m_name.setFillColor(color);
        // m_name.setPosition(x, y);
    }

    sf::RectangleShape& getRect()
    {
        return rect;
    }

    //! inheritance
    float getSpeedX() 
    {
        return m_sx;
    }

    float getSpeedY() 
    {
        return m_sy;
    }

    void setSpeedX(float sx) 
    {
        m_sx = sx;
    }

    void setSpeedY(float sy)
    {
        m_sy = sy;
    }
    //! inheritance

};

class ShapeKeeper
{
    std::vector<CircleWrapper> circles;
    std::vector<RectWrapper> rects;

    sf::Font font;

    int windowWidth;
    int windowHeight;

    std::string fontPath;
    int fontSize;

    int fontR;
    int fontG;
    int fontB;

public:

    ShapeKeeper() {}

    sf::Font getFont()
    {
        return font;
    }

    int getFontR()
    {
        return fontR;
    }

    int getFontG()
    {
        return fontG;
    }

    int getFontB()
    {
        return fontB;
    }

    int getFontSize()
    {
        return fontSize;
    }

    void setFont(
        const std::string& path, 
        const int size, 
        const int R, 
        const int G, 
        const int B
    ) 
    {
        if (!font.loadFromFile(path)) 
        {
            std::cerr << "Could not load the font" << std::endl;
            exit(-1);
        }

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

    int getWindowWidth()
    {
        return windowWidth;
    }

    int getWindowHeight()
    {
        return windowHeight;
    }

    std::vector<CircleWrapper> getCircles()
    {
        return circles;
    }

    std::vector<RectWrapper> getRects()
    {
        return rects;
    }

    void readShapesFromFile(const std::string& filename)
    {
        //input file stream
        std::ifstream fileStream(filename);

        std::string name, text;

        float x, y, sx, sy, r;
        int   R, G, B, w, h, W, H;

        std::string fontPath;

        int fontSize, fontR, fontG, fontB;

        while (fileStream >> name)
        {
            if (name == "Window") 
            {
                fileStream >> W >> H;
                setWindowSettings(W, H);
            }

            if (name == "Font") 
            {
                fileStream >> fontPath >> fontSize >> fontR >> fontG >> fontB;
                setFont(fontPath, fontSize, fontR, fontG, fontB);
            }

            if (name == "Circle") 
            {
                fileStream >> text >> x >> y >> sx >> sy >> R >> G >> B >> r;
                circles.push_back(CircleWrapper(text, x, y, sx, sy, R, G, B, r, getFont(), getFontSize(), getFontR(), getFontG(), getFontB()));
            }

            if (name == "Rectangle")
            {
                fileStream >> text >> x >> y >> sx >> sy >> R >> G >> B >> w >> h;
                rects.push_back(RectWrapper(text, x, y, sx, sy, R, G, B, w, h, getFont(), getFontSize(), getFontR(), getFontG(), getFontB()));
            }
        }
    }
};

int main()
{
    ShapeKeeper shapeKeeper;

    shapeKeeper.readShapesFromFile("config.txt");

    sf::RenderWindow window(sf::VideoMode(shapeKeeper.getWindowWidth(), shapeKeeper.getWindowHeight()), "GAME KEITH");

    // set frame rate limit
    // to run app at a given frame rate 
    // instead of monitor's frequency
    window.setFramerateLimit(60);

    std::vector<CircleWrapper> circles = shapeKeeper.getCircles();
    std::vector<RectWrapper> rects = shapeKeeper.getRects();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (auto& c : circles) 
        {
            // std::cout << c.getCircle().getPosition().x << " C position X" << std::endl;
            // std::cout << c.getSpeedX() << " c get speed x" << std::endl;
            // std::cout << " " << std::endl;
            // std::cout << c.getCircle().getPosition().y << " C position Y" << std::endl;
            // std::cout << c.getSpeedY() << " c get speed y" << std::endl;

            c.getCircle().setPosition(
                c.getCircle().getPosition().x + c.getSpeedX(),
                c.getCircle().getPosition().y + c.getSpeedY()
            );

            if (
                c.getCircle().getPosition().x < 0 || 
                c.getCircle().getPosition().x + (c.getCircle().getRadius()) * 2 > window.getSize().x
            ) 
            {
                c.setSpeedX(-c.getSpeedX());
            }

            if (
                c.getCircle().getPosition().y < 0 || 
                c.getCircle().getPosition().y + (c.getCircle().getRadius()) * 2 > window.getSize().y
            ) 
            {
                c.setSpeedY(-c.getSpeedY());
            }

            window.draw(c.getCircle());
        }

        for (auto& r : rects) 
        {
            r.getRect().setPosition(
                r.getRect().getPosition().x + r.getSpeedX(),
                r.getRect().getPosition().y + r.getSpeedY()
            );


            if (
                r.getRect().getPosition().x < 0 || 
                r.getRect().getPosition().x + r.getRect().getSize().x > window.getSize().x
                ) 
            {
                r.setSpeedX(-r.getSpeedX());
            }

            if (
                r.getRect().getPosition().y < 0 || 
                r.getRect().getPosition().y + r.getRect().getSize().y > window.getSize().y
            ) 
            {
                r.setSpeedY(-r.getSpeedY());
            }

            window.draw(r.getRect());
        }

        // window.draw(text);

        window.display();
    }

    return 0;
}