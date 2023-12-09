# SFML install

Brew install sfml
Brew info sfml

## Before:

- create bin folder
- main.cpp might be replaced with something like src/*.cpp - to build all cpp files inside src folder

`g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include  -std=c++17 -o bin/sfmlgame -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio`