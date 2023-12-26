#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(480, 480), "15_game works!");

    Texture t;
    t.loadFromFile("D:\\laboaip\\game15\\picture\\15gamepicture.jpg"); // загружаем всю картинку
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
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                n = grid[i + 1][j + 1];
                s[n].setPosition(i * w, j * w);
                window.draw(s[n]);
            }
        window.display();
    }

    return 0;
}