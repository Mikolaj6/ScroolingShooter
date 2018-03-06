#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Upgrades.h"
#include "PBullet.h"

using std::cout;
using std::endl;

extern sf::VideoMode my_mode;

extern int score;
extern int MaxScore;
extern int credits;

class upgrades;

class Player{
public:
    upgrades *wsk_upgrades;

    sf::Vector2f player_position;           ///Positioning
    float bottom_line;
    float right_line;


    const std::string player_file_name;     ///Sprite and stuff
    sf::Texture player_texture;
    sf::Sprite player_sprite[3];
    int sprite_num;

    std::vector <PBullet *> PBull_belt;       ///All the bullets

    Player(upgrades * );

    void Player_move(sf::RenderWindow & );

    int counter;                                    ///Counter for changing sprites
    void Player_ShangeSprites();

    void Player_draw(sf::RenderWindow & );

    void Player_management(sf::RenderWindow & );   ///This function will be in main

    inline float get_top();
    inline float get_bottom();
    inline float get_left();
    inline float get_right();

    ///Bullet stuff below
    void PBull_manager_P(sf::RenderWindow & );
    //void Create_bullet();
    bool space_pressed;
    bool can_fire;
    float Act_ROF;
    float ROF_counter;
    //bool Ovrheated;
    float Overheat_counter;
    float Overheat_regeneration;
    bool jammed;

    void del_off_PBull();
    void set_regeneration();
    void set_Act_ROF();

    ///Speed
    float Speed_actual;
    void set_speed();

    void delete_bullet(int );
    void Player_Reset();
};



#endif // Player
