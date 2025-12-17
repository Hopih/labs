#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

const int CELL_SIZE = 40;
const int WIDTH = 15;
const int HEIGHT = 15;

enum class CellType {
    EMPTY,
    WALL,
    TREASURE,
    ENEMY
};

struct Player {
    int x, y;
    int treasures;
};

class Game {
private:
    std::vector<std::vector<CellType>> maze;
    Player player;
    std::vector<std::pair<int, int>> enemies;
    bool gameOver;
    sf::RenderWindow window;
    
    sf::Texture playerTexture;
    sf::Texture wallTexture;
    sf::Texture treasureTexture;
    sf::Texture enemyTexture;
    sf::Texture floorTexture;
    
    sf::Sprite playerSprite;
    sf::Sprite wallSprite;
    sf::Sprite treasureSprite;
    sf::Sprite enemySprite;
    sf::Sprite floorSprite;
    
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;

public:
    Game() : window(sf::VideoMode(WIDTH * CELL_SIZE, HEIGHT * CELL_SIZE + 50), "Лабиринт с сокровищами") {
        initializeGame();
        loadTextures();
        setupSprites();
        setupUI();
    }

    void initializeGame() {
        maze.resize(HEIGHT, std::vector<CellType>(WIDTH, CellType::EMPTY));
        generateMaze();
        
        player = {1, 1, 0};
        gameOver = false;
        
        // Добавляем врагов
        enemies.clear();
        enemies.push_back({5, 5});
        enemies.push_back({10, 8});
        enemies.push_back({7, 12});
    }

    void generateMaze() {
        // Создаем границы
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1) {
                    maze[i][j] = CellType::WALL;
                }
            }
        }
        
        // Добавляем случайные стены
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 4);
        
        for (int i = 2; i < HEIGHT - 2; i++) {
            for (int j = 2; j < WIDTH - 2; j++) {
                if (dis(gen) == 0) {
                    maze[i][j] = CellType::WALL;
                }
            }
        }
        
        // Добавляем сокровища
        for (int i = 0; i < 8; i++) {
            int x, y;
            do {
                x = dis(gen) % (WIDTH - 2) + 1;
                y = dis(gen) % (HEIGHT - 2) + 1;
            } while (maze[y][x] != CellType::EMPTY || (x == 1 && y == 1));
            
            maze[y][x] = CellType::TREASURE;
        }
        
        // Гарантируем проходимость
        maze[1][2] = CellType::EMPTY;
        maze[2][1] = CellType::EMPTY;
    }

    void loadTextures() {
        // Создаем простые текстуры программно
        playerTexture.create(CELL_SIZE, CELL_SIZE);
        wallTexture.create(CELL_SIZE, CELL_SIZE);
        treasureTexture.create(CELL_SIZE, CELL_SIZE);
        enemyTexture.create(CELL_SIZE, CELL_SIZE);
        floorTexture.create(CELL_SIZE, CELL_SIZE);
        
        // Заполняем цветами
        sf::Uint8* pixels = new sf::Uint8[CELL_SIZE * CELL_SIZE * 4];
        
        // Игрок (синий)
        for (int i = 0; i < CELL_SIZE * CELL_SIZE * 4; i += 4) {
            pixels[i] = 0;      // R
            pixels[i+1] = 0;    // G
            pixels[i+2] = 255;  // B
            pixels[i+3] = 255;  // A
        }
        playerTexture.update(pixels);
        
        // Стены (серые)
        for (int i = 0; i < CELL_SIZE * CELL_SIZE * 4; i += 4) {
            pixels[i] = 128;
            pixels[i+1] = 128;
            pixels[i+2] = 128;
            pixels[i+3] = 255;
        }
        wallTexture.update(pixels);
        
        // Сокровища (желтые)
        for (int i = 0; i < CELL_SIZE * CELL_SIZE * 4; i += 4) {
            pixels[i] = 255;
            pixels[i+1] = 255;
            pixels[i+2] = 0;
            pixels[i+3] = 255;
        }
        treasureTexture.update(pixels);
        
        // Враги (красные)
        for (int i = 0; i < CELL_SIZE * CELL_SIZE * 4; i += 4) {
            pixels[i] = 255;
            pixels[i+1] = 0;
            pixels[i+2] = 0;
            pixels[i+3] = 255;
        }
        enemyTexture.update(pixels);
        
        // Пол (зеленый)
        for (int i = 0; i < CELL_SIZE * CELL_SIZE * 4; i += 4) {
            pixels[i] = 0;
            pixels[i+1] = 255;
            pixels[i+2] = 0;
            pixels[i+3] = 255;
        }
        floorTexture.update(pixels);
        
        delete[] pixels;
    }

    void setupSprites() {
        playerSprite.setTexture(playerTexture);
        wallSprite.setTexture(wallTexture);
        treasureSprite.setTexture(treasureTexture);
        enemySprite.setTexture(enemyTexture);
        floorSprite.setTexture(floorTexture);
    }

    void setupUI() {
        if (!font.loadFromFile("arial.ttf")) {
            // Если шрифт не загружен, используем системный
            std::cout << "Шрифт не найден, используем стандартный\n";
        }
        
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, HEIGHT * CELL_SIZE + 10);
        
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setString("ИГРА ОКОНЧЕНА! Нажмите R для рестарта");
        gameOverText.setPosition(WIDTH * CELL_SIZE / 4, HEIGHT * CELL_SIZE / 2);
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            if (!gameOver) {
                update();
            }
            render();
        }
    }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (gameOver) {
                    if (event.key.code == sf::Keyboard::R) {
                        initializeGame();
                    }
                } else {
                    handleInput(event.key.code);
                }
            }
        }
    }

    void handleInput(sf::Keyboard::Key key) {
        int newX = player.x;
        int newY = player.y;
        
        switch (key) {
            case sf::Keyboard::W: newY--; break;
            case sf::Keyboard::S: newY++; break;
            case sf::Keyboard::A: newX--; break;
            case sf::Keyboard::D: newX++; break;
            default: break;
        }
        
        // Проверяем, можно ли переместиться
        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
            if (maze[newY][newX] != CellType::WALL) {
                player.x = newX;
                player.y = newY;
                checkCell(newX, newY);
            }
        }
    }

    void checkCell(int x, int y) {
        // Проверяем сокровища
        if (maze[y][x] == CellType::TREASURE) {
            player.treasures++;
            maze[y][x] = CellType::EMPTY;
            std::cout << "Собрано сокровищ: " << player.treasures << std::endl;
        }
        
        // Проверяем врагов
        for (const auto& enemy : enemies) {
            if (enemy.first == x && enemy.second == y) {
                gameOver = true;
                std::cout << "Вы попались врагу! Игра окончена." << std::endl;
                return;
            }
        }
        
        // Победа при сборе всех сокровищ
        if (player.treasures >= 8) {
            gameOver = true;
            std::cout << "Поздравляем! Вы собрали все сокровища!" << std::endl;
        }
    }

    void update() {
        // Двигаем врагов случайным образом
        static sf::Clock enemyClock;
        if (enemyClock.getElapsedTime().asSeconds() > 0.5f) {
            moveEnemies();
            enemyClock.restart();
        }
        
        // Проверяем столкновение с врагами после их движения
        for (const auto& enemy : enemies) {
            if (enemy.first == player.x && enemy.second == player.y) {
                gameOver = true;
                return;
            }
        }
    }

    void moveEnemies() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);
        
        for (auto& enemy : enemies) {
            int direction = dis(gen);
            int newX = enemy.first;
            int newY = enemy.second;
            
            switch (direction) {
                case 0: newY--; break; // вверх
                case 1: newY++; break; // вниз
                case 2: newX--; break; // влево
                case 3: newX++; break; // вправо
            }
            
            // Враги могут ходить только по пустым клеткам
            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && 
                maze[newY][newX] != CellType::WALL && maze[newY][newX] != CellType::TREASURE) {
                enemy.first = newX;
                enemy.second = newY;
            }
        }
    }

    void render() {
        window.clear();
        
        // Рисуем лабиринт
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                sf::Sprite* spriteToDraw = &floorSprite;
                
                switch (maze[y][x]) {
                    case CellType::WALL: spriteToDraw = &wallSprite; break;
                    case CellType::TREASURE: spriteToDraw = &treasureSprite; break;
                    default: spriteToDraw = &floorSprite; break;
                }
                
                spriteToDraw->setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(*spriteToDraw);
            }
        }
        
        // Рисуем врагов
        for (const auto& enemy : enemies) {
            enemySprite.setPosition(enemy.first * CELL_SIZE, enemy.second * CELL_SIZE);
            window.draw(enemySprite);
        }
        
        // Рисуем игрока
        playerSprite.setPosition(player.x * CELL_SIZE, player.y * CELL_SIZE);
        window.draw(playerSprite);
        
        // Рисуем UI
        scoreText.setString("Сокровища: " + std::to_string(player.treasures) + "/8");
        window.draw(scoreText);
        
        if (gameOver) {
            window.draw(gameOverText);
        }
        
        window.display();
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}



