#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(480, 480), "15_game works!");

    Texture t;
    t.loadFromFile("D:\\laboaip\\game15\\picture\\15gamepictureNonBorderedREAL.jpg"); // загружаем всю картинку
    Sprite s[17]; //создаем спрайт картинки . ADDED - по частям
    int w = 120; //px одна часть
    int grid[6][6] = { 0 }; //массив хранящий идентификатор(кникальный)каждой "цифры" (ее изображения)
    int n = 0; // уникальный индекс

    for (int i = 0; i < 4; i++) {// Перебираем строки
        for (int j = 0; j < 4; j++) { // Перебираем столбцы
            n++; // Увеличиваем счетчик уникального индекса
            s[n].setTexture(t); // связывание текстуры и спрайта s[n]
            s[n].setTextureRect(IntRect(i * w, j * w, w, w)); // Устанавливаем прямоугольник текстуры для спрайта s[n]
            grid[i + 1][j + 1] = n; // Обновляем сетку с индексом спрайта
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {

            // Закрытие окна
            if (event.type == Event::Closed)
                window.close();

            // Обработка нажатия левой кнопки мыши
            if (event.type == Event::MouseButtonPressed)
            {
                // Проверка нажатия левой кнопки мыши
                if (event.key.code == Mouse::Left) {

                    // Получение позиции мыши
                    Vector2i pos = Mouse::getPosition(window);

                    // Вычисление координат ячейки в сетке
                    int x = pos.x / w + 1;
                    int y = pos.y / w + 1;

                    // Переменные для смещения ячейки
                    int dx = 0;
                    int dy = 0;

                    // Проверка соседних ячеек на наличие пустой ячейки (с индексом 16)
                    if (grid[x + 1][y] == 16) {
                        dx = 1;
                        dy = 0;
                    }
                    if (grid[x - 1][y] == 16) {
                        dx = -1;
                        dy = 0;
                    }
                    if (grid[x][y + 1] == 16) {
                        dx = 0;
                        dy = 1;
                    }
                    if (grid[x][y - 1] == 16) {
                        dx = 0;
                        dy = -1;
                    }

                    // Обновление сетки путем перемещения ячейки
                    n = grid[x][y];
                    grid[x][y] = 16;
                    grid[x + dx][y + dy] = n;
                }
            }
        }

        // Очистка окна
        window.clear();

        // Отрисовка спрайтов
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // Получение индекса спрайта из сетки
                n = grid[i + 1][j + 1];

                // Установка позиции спрайта
                s[n].setPosition(i * w, j * w);

                // Отрисовка спрайта
                window.draw(s[n]);
            }
        }

        // Отображение окна
        window.display();
    }

    return 0;
}

