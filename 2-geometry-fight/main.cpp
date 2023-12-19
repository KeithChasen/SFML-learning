#include <SFML/Graphics.hpp>

#include <iostream>

#include "Game.h"

#include "Vec2.cpp"

int main()
{
    // Game g("config.txt");
    // g.run();

    Vec2 v1(100.0, 200.0);
    Vec2 v2(20.0, 35.0);

    std::cout << v1.x << " " << v1.y << std::endl;

    std::cout << v2.x << " " << v2.y << std::endl;

    bool res = v2 != v1;

    std::cout << res << std::endl;

    Vec2 v3 = v1 + v2;

    std::cout << "+: " << v3.x << " " << v3.y << std::endl;

    Vec2 v4 = v1 - v2;

    std::cout << "-: " << v4.x << " " << v4.y << std::endl;

    Vec2 v5 = v1 / 2.0;

    std::cout << "/: " << v5.x << " " << v5.y << std::endl;

     Vec2 v6 = v1 * 4.0;

    std::cout << "*: " << v6.x << " " << v6.y << std::endl;
}