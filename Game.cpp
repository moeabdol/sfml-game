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
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "My First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
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

void Game::update() {
    // Get mouse position
    std::cout << "Mouse pos: "
              << sf::Mouse::getPosition(*this-> window).x
              << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render() {
    this->window->clear();      // Clears old frame

    // Draw game objects
    this->window->draw(this->enemy);

    this->window->display();    // Display new drawing
}
