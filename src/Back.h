#pragma once
#include "Line.h"
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include <vector>
#include <iostream>



class Background{
    private:
        sf::RectangleShape back;
        float m1;
        float m2;
        float x_1;
        float y_1;
        float x_2;
        float y_2;
    public:
        Background() {
            back.setSize(sf::Vector2f(600.f, 600.f));
        }
        Background(Background &t){
            this->back = t.back;
            this->m1 = t.m1;
            this->m2 = t.m2;
            this->x_1 = t.x_1;
            this->y_1 = t.y_1;
            this->x_2 = t.x_2;
            this->y_2 = t.y_2;
        }
        void draw_back(sf::RenderWindow &window){
            back.setFillColor(sf::Color::White);
            window.draw(back);
            window.display();
        }
};

/*struct my_type
{
    Line lin;
    Background back;
    sf::CircleShape cir;
};*/
void draw_back_line(sf::RenderWindow &t);

void draw_all(sf::RenderWindow &t, std::vector <Line> l, std::vector <sf::CircleShape> c, Background &back){
    t.clear();
    back.draw_back(t);
    for (int i=0; i<l.size(); i++){
        l[i].draw_line_n(t);
        t.display();
    }
    for (int i=0; i<c.size(); i++){
        t.draw(c[i]);
        t.display();
    }
    draw_back_line(t);
        
}
void draw_back_line(sf::RenderWindow &window){
           for (int i=0; i<600; i=i+100){
                Line t(0, i, 600, i);
                t.draw_line_n(window);

           }}