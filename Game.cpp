#include "Game.h"

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game() {
    delete this->window;
}

void Game::initVariables() {
    this->window = nullptr;

    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(50.f, 50.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    //this->enemy.setOutlineColor(sf::Color::Green);
    //this->enemy.setOutlineThickness(1.f);
}

bool Game::isRunning() {
    return this->window->isOpen();
}

void Game::pollEvents() {
    while(this->window->pollEvent(this->event)) {
        switch(this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }

}

void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::spawnEnemy() {
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );
    this->enemy.setFillColor(sf::Color::Green);
    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer > this->enemySpawnTimerMax) {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        } else
            this->enemySpawnTimer += 1.f;
    }

    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i].move(0.f, 1.f);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                this->enemies.erase(this->enemies.begin() + i);
            }
        }
    }
}

void Game::update() {
    this->updateEnemies();
}

void Game::renderEnemies() {
    for (auto &e : this->enemies) {
        this->window->draw(e);
    }
}

void Game::render() {
    this->window->clear();      // Clears old frame

    // Draw game objects
    this->renderEnemies();

    this->window->display();    // Display new drawing
}
