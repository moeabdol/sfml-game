#include <iostream>
#include <vector>
#include <ctime>
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
        // Window
        sf::RenderWindow * window;
        sf::Event event;
        sf::VideoMode videoMode;

        // Mouse
        sf::Vector2i mousePosWindow;

        // Game logic
        int points;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        int maxEnemies;

        // Game objects
        sf::RectangleShape enemy;
        std::vector<sf::RectangleShape> enemies;

        void initVariables();
        void initWindow();
        void initEnemies();

    public:
        Game();
        virtual ~Game();
        bool isRunning();
        void pollEvents();
        void updateMousePositions();
        void spawnEnemy();
        void updateEnemies();
        void update();
        void renderEnemies();
        void render();
};
