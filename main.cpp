#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "My First Game", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    // Game loop
    while(window.isOpen()) {
        // Event polling
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }

        // Update game

        // Render game
        window.clear(sf::Color::Blue);     // Clears old frame

        window.display();   // Display new drawing
    }

    return 0;
}
