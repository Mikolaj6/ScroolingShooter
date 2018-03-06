#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Inputs.h"
#include "Functions.h"

using std::cout;
using std::endl;


extern int game_state;

extern sf::VideoMode my_mode;


class Game{
public:

    sf::Texture menu_texture;
    sf::Sprite Menu_sprite_1;
    sf::Sprite Menu_sprite_2;
    sf::Sprite Menu_sprite_3;
    sf::Sprite Menu_sprite_4;

    sf::Texture Pause_texture;
    sf::Sprite Pause_sprite;

    void draw_Pause(sf::RenderWindow &);

    int menu_position;

    Game();

    void Menu_handling(sf::RenderWindow &);

};



#endif // Game_hpp
