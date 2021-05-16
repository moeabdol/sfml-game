#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    // Initialze srand
    std::srand(static_cast<unsigned>(time(NULL)));

    // Initialize game engine
    Game game;

    // Game loop
    while(game.isRunning()) {
        // Poll events
        game.pollEvents();

        // Update mouse positions
        game.updateMousePositions();

        // Update game
        game.update();

        // Render game
        game.render();
    }

    return 0;
}
