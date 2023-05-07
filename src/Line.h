#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Circle.h"

class Line{
     private:
        float x1;
        float y1;
        float x2;
        float y2;
        float x;
        float y;
        float x_t;
        float y_t;
        float x_z;
        float y_z;
        float rad;

    public:
        Line(float x1, float y1, float x2, float y2){
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
            this->x = this->x2 - this->x1;
            this->y = this->y2 - this->y1;
            this->x_t = -x/x;
            this->y_t = x/y;
            this->x_z = x1 + x/2;
            this->y_z = y1 + y/2;
            this->rad = sqrt(x_t * x_t +y_t*y_t);
        }
        Line(){
            this->x1 = 0;
            this->y1 = 0;
            this->x2 = 0;
            this->y2 = 0;
            this->x = 0;
            this->y = 0;
            this->x_t = 0;
            this->y_t = 0;
            this->x_z = 0;
            this->y_z = 0;
            this->rad = 0;
        }
        void draw_line_n(sf::RenderWindow &window){
            for (int i=-850; i<850; i++){
                sf::CircleShape n = sf::CircleShape(1);
                n.setFillColor(sf::Color::Black);
                n.setPosition(x_z + x_t/rad * i, y_z + y_t/rad * i);
                window.draw(n);
            }}
        /*float *print(){
            float *mas = new int[4];
            mas[0] = this->x_z + (-850) * x_t/rad;
            mas[1] = this->y_z + (-850) * y_t/rad;
            mas[2] = this->x_z + (850) * x_t/rad;
            mas[3] = this->y_z + (850) * y_t/rad;
            return mas;
        }*/
        float say_v_x(){
            return x_t;
        }
        float say_v_y(){
            return x_t;
        }
        float say_x_z(){
            return x_z;
        }
        float say_y_z(){
            return y_z;
        }
};


