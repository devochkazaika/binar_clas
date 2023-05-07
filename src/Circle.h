#pragma once
#include <SFML/Graphics.hpp>


struct circle{
    sf::CircleShape *mas_g = new sf::CircleShape[100];
    int n_g = 0;
    float sr_g_x;
    float sr_g_y;
    float sr_r_x;
    float sr_r_y;
    sf::CircleShape *mas_r = new sf::CircleShape[100];
    int n_r = 0;
};

void sr(circle &t);

void draw_all_krug(sf::RenderWindow &window, circle &t){
    for (int i=0; i<t.n_g; i++){
        window.draw(t.mas_g[i]);
    }
    for (int i=0; i<t.n_r; i++){
        window.draw(t.mas_r[i]);
    }
}

void sr(circle &t){
    float sum_g_x = 0;
    float sum_g_y = 0;
    float sum_r_x = 0;
    float sum_r_y = 0;
    for (int i=0; i<t.n_g; i++){
        sum_g_x += t.mas_g[i].getPosition().x;
        sum_g_y += t.mas_g[i].getPosition().y;
    }
    for (int i=0; i<t.n_r; i++){
        sum_r_x += t.mas_r[i].getPosition().x;
        sum_r_y += t.mas_r[i].getPosition().y;
    }
    t.sr_g_x = sum_g_x/t.n_g;
    t.sr_g_y = sum_g_y/t.n_g;
    t.sr_r_x = sum_r_x/t.n_g;
    t.sr_r_y = sum_r_y/t.n_g;
}


