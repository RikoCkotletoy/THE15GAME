#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprites[17];
    int grid[6][6] = { 0 };
    int cellSize = 120;

    void loadTexture();
    void initializeSprites();
    void handleEvents();
    void handleMouseClick();
    void handleKeyPress(sf::Keyboard::Key key);
    void shuffleTiles();
    void moveTile(int x, int y);
    void update();
    void render();
};
