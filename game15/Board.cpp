// Board.cpp
#include "Board.h"
#include <SFML/Graphics.hpp>


void Board::render(sf::RenderWindow& window, sf::Sprite sprites[], int cellSize, int grid[][6]) {
    window.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int n = grid[i + 1][j + 1];
            sprites[n].setPosition(i * cellSize, j * cellSize);
            window.draw(sprites[n]);
        }
    }
    window.display();
}

