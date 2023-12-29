#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
class Board {
public:
    Board();

    void render(RenderWindow& window, Sprite sprites[], int cellSize, int grid[][6]);
};
 