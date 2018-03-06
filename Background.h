#ifndef Background_hpp
#define Background_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;

extern sf::VideoMode my_mode;


class Background{
public:
    sf::Texture water_texture;
    sf::Sprite water_sprite;
    float counter;
    float scrolling_speed;


    int sprite_height;
    int difference;

    /*    */
    sf::Texture texture_1;
    sf::Texture texture_2;
    sf::Texture texture_3;


    sf::Sprite *arr_islands;

    int how_many_islands;
    int island_spacing;
    float real_spacig;


    void Island_movement();
    void Island_init_positioning();


    void draw_everything(sf::RenderWindow& window);
    void Background_movement();

    Background();
    ~Background();
};

#endif // Background_hpp
