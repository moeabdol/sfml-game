#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    // Initialize game engine
    Game game;

    // Game loop
    while(game.isRunning()) {
        // Poll events
        game.pollEvents();

        // Update game
        game.update();

        // Render game
        game.render();
    }

    return 0;
}
