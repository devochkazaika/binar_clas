#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "math.h"

struct coords{
    int x;
    int y;
    int colour;
};

class train_mas{

    public:
        int n;
        coords *mas;
        int w0;
        int b;
        train_mas(){
            n = 0;
            mas = new coords[40];
            w0 = 0;
            b = 0;
        }
        void insert(sf::CircleShape &t){
            mas[n].x = t.getPosition().x;
            mas[n].y = t.getPosition().y;
            if (t.getFillColor() == sf::Color::Green) mas[n].colour = 1;
            else mas[n].colour = -1;
            n++;
        }

};

int Q(float w, float b, train_mas &train);

float sign(float x){
    float result = exp (-x);
    return (1/ (result+1));
}

float M(float x, float y, float w, float b){
    return sign(x*w + b) * y;
}

int Q(float w, float b, train_mas &train){
    int sum = 0;
    for (int i=0; i<train.n; i++){
        if (M(train.mas[i].x, train.mas[i].y, w, b) < 0){
            sum++;
        }
    }
    return sum;
}
void learn(train_mas){
}
