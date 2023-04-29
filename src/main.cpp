#include <SFML/Graphics.hpp>
#include "functions.h"
#include <iostream>

using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(50.f);
    sf::CircleShape *mas_c;
    circle circle_obj;

    shape.setFillColor(sf::Color(100, 250, 50));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == Keyboard::Space){
                    window.clear();
                    draw_line_n(window, circle_obj.sr_g_x, circle_obj.sr_g_y, circle_obj.sr_r_x, circle_obj.sr_r_y);
                    window.display();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    CircleShape obj(10);
                    obj.setFillColor(sf::Color(100, 250, 50));
                    obj.setPosition(event.mouseButton.x-10, event.mouseButton.y-10);
                    circle_obj.mas_g[circle_obj.n_g] = obj;
                    circle_obj.n_g += 1;
                    sr(circle_obj);
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    CircleShape obj(10);
                    obj.setFillColor(sf::Color::Red);
                    obj.setPosition(event.mouseButton.x-10, event.mouseButton.y-10);
                    circle_obj.mas_r[circle_obj.n_r] = obj;
                    circle_obj.n_r += 1;
                    sr(circle_obj);
                }

            }
        }
        //RectangleShape line(Vector2f(900, 5));
        //line.setPosition(-5, 595);

        //window.clear();
        draw_all_krug(window, circle_obj);
        //draw_line(window, circle_obj);

        //window.draw(line);
        window.display();
    }

    return 0;
}
