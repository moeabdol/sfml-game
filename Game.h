#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#pragma once

/*
    Game engine class.
*/

class Game {
    private:
        sf::RenderWindow * window;
        sf::Event event;
        sf::VideoMode videoMode;

        sf::RectangleShape enemy;

        void initVariables();
        void initWindow();
        void initEnemies();

    public:
        Game();
        virtual ~Game();
        bool isRunning();
        void pollEvents();
        void update();
        void render();
};
