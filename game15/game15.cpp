#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "SFML works!");

    Texture t;
    t.loadFromFile("D:\\laboaip\\game15\\picture\\15pyatnashki01@fhd.jpg"); // загружаем всю картинку
    Sprite s(t); //создаем спрайт картинки
    sf::CircleShape shape(1080.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(s);
        window.display();
    }

    return 0;
}
