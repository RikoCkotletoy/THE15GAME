#include "Game.h"
#include "Board.h"
#include <random>
#include <vector>

Game::Game() : window(sf::VideoMode(480, 480), "Tag Game", sf::Style::Titlebar | sf::Style::Close) {
    Board* board;
    loadTexture();
    initializeSprites();
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}

void Game::loadTexture() {
	texture.loadFromFile("C:\\Users\\Евгений\\Desktop\\game15\\picture\\15gamepictureNonBorderedREAL.jpg");
    
}

void Game::initializeSprites() {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            n++;
            sprites[n].setTexture(texture);
            sprites[n].setTextureRect(sf::IntRect(i * cellSize, j * cellSize, cellSize, cellSize));
            grid[i + 1][j + 1] = n;
        }
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
            handleMouseClick();
        }

        if (event.type == sf::Event::KeyPressed) {
            handleKeyPress(event.key.code);
        }
    }
}

void Game::handleMouseClick() {
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int x = pos.x / cellSize + 1;
    int y = pos.y / cellSize + 1;
    moveTile(x, y);
}

void Game::handleKeyPress(sf::Keyboard::Key key) {
    // Check for a specific key (e.g., space) to trigger shuffling
    if (key == sf::Keyboard::Space) {
        shuffleTiles();
    }
}

void Game::shuffleTiles() {
    // Flatten the 2D grid into a 1D vector for shuffling
    std::vector<int> tiles;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            tiles.push_back(grid[i][j]);
        }
    }

    // Use a random engine to shuffle the tiles
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(tiles.begin(), tiles.end(), rng);

    // Update the grid with the shuffled tiles
    int index = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            grid[i][j] = tiles[index++];
        }
    }
}

void Game::moveTile(int x, int y) {
    int dx = 0, dy = 0;

    if (grid[x + 1][y] == 16) {
        dx = 1;
        dy = 0;
    }
    else if (grid[x - 1][y] == 16) {
        dx = -1;
        dy = 0;
    }
    else if (grid[x][y + 1] == 16) {
        dx = 0;
        dy = 1;
    }
    else if (grid[x][y - 1] == 16) {
        dx = 0;
        dy = -1;
    }

    int n = grid[x][y];
    grid[x][y] = 16;
    grid[x + dx][y + dy] = n;
}

void Game::render() {
    board->render(window, sprites, cellSize, grid);
}