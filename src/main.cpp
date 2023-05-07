#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Circle.h"
#include "Back.h"
#include <iostream>
#include <vector>
#include "Train.h"


using namespace sf;
float want_fps = 60;
sf::Clock loop_timer;
std::vector <Line> lines;
std::vector <sf::CircleShape> circles;
Background back;

int main()
{  

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(50.f);
    circle circle_obj;

    shape.setFillColor(sf::Color(100, 250, 50));
    back.draw_back(window);
    draw_back_line(window);
    train_mas train;

    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == Keyboard::Space){
                    if (lines.size())
                    lines.resize(lines.size() - 1);
                    Line t(circle_obj.sr_g_x, circle_obj.sr_g_y, circle_obj.sr_r_x, circle_obj.sr_r_y);
                    t.draw_line_n(window);
                    lines.push_back(t);
                    window.display();
                    draw_all(window, lines, circles, back);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::CircleShape c(10);
                    c.setFillColor(sf::Color(100, 250, 50));
                    c.setPosition(event.mouseButton.x-10, event.mouseButton.y-10);
                    circle_obj.mas_g[circle_obj.n_g] = c;
                    circle_obj.n_g += 1;
                    sr(circle_obj);
                    circles.push_back(c);
                    train.insert(c);
                    window.draw(c);
                    window.display();
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::CircleShape c(10);
                    c.setFillColor(sf::Color::Red);
                    c.setPosition(event.mouseButton.x-10, event.mouseButton.y-10);
                    circle_obj.mas_r[circle_obj.n_r] = c;
                    circle_obj.n_r += 1;
                    sr(circle_obj);
                    circles.push_back(c);
                    train.insert(c);
                    window.draw(c);
                    window.display();
                }

            }
        }
        //RectangleShape line(Vector2f(900, 5));
        //line.setPosition(-5, 595);
        
        //window.clear();
        //t.draw_line_n(window);
        //back.draw_back(window);
        //draw_line(window, circle_obj);
        //window.draw(biba);
        //window.draw(line);
        sf::Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds();
        sf::Int32 time_to_sleep = int(1000.f/want_fps) - frame_duration;
        if (time_to_sleep > 0) {
                sf::sleep(sf::milliseconds(time_to_sleep));
            }
            loop_timer.restart();
    }

    return 0;
}
