#pragma once

#include <SFML/Graphics.hpp>

class Board {
public:
    Board();

    void render(sf::RenderWindow& window, sf::Sprite sprites[], int cellSize, int grid[][6]);
};
 