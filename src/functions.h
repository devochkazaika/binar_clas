#include <SFML/Graphics.hpp>
using namespace sf;

struct circle{
    CircleShape *mas_g = new CircleShape[100];
    int n_g = 0;
    float sr_g_x;
    float sr_g_y;
    float sr_r_x;
    float sr_r_y;
    CircleShape *mas_r = new CircleShape[100];
    int n_r = 0;

};

struct line{
    CircleShape mas[2];
};


void draw_line_n(RenderWindow &window, float x1, float y1, float x2, float y2){
    float x = x2 - x1;
    float y = y2 - y1;
    float x_t = -20/x;
    float y_t = 20/y;
    float x_z = x1 + x/2;
    float y_z = y1 + y/2;
    for (int i=-1000; i<1000; i++){
        CircleShape n = CircleShape(1);
        n.setPosition(x_z + x_t *i*20, y_z + y_t * i *20);
        window.draw(n);
    }
}

void draw_all_krug(RenderWindow &window, circle &t){
    for (int i=0; i<t.n_g; i++){
        window.draw(t.mas_g[i]);
    }
    for (int i=0; i<t.n_r; i++){
        window.draw(t.mas_r[i]);
    }
}

void draw_line(RenderWindow &window, circle &t){

        for (int i=1; i<t.n_g; i++){
        float x = (t.mas_g[i].getPosition().x - t.mas_g[i-1].getPosition().x);
        float y = (t.mas_g[i].getPosition().y - t.mas_g[i-1].getPosition().y);
        int z = 100;
        for (int j=0; j<z+1; j++){
            CircleShape k = CircleShape(1);
            k.setPosition(float(t.mas_g[i-1].getPosition().x+10) + j*(x/z), float(t.mas_g[i-1].getPosition().y+10) + j*(y/z));
            window.draw(k);
        }}
}

//void draw_sr_lin(RenderWindow &window)


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


