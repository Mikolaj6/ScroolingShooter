#ifndef upgrades_hpp
#define upgrades_hpp

#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using std::cout;
using std::endl;

extern float game_scale_x;
extern float game_scale_y;

extern int MaxScore;
extern int credits;

extern sf::VideoMode my_mode;

class Game;

class upgrades{
public:

    Game *wsk;


    sf::Texture upgrades_texture;
    sf::Sprite Upgrades_sprite;

    upgrades(Game *);

    ///Plane:Speed
    int Speed_level;
    sf::FloatRect Speed_button;
    sf::Vector2f first_pos_speed;
    sf::RectangleShape rectangle_speed[4];

    ///Plane:Armour
    int Armour_level;
    sf::FloatRect Armour_button;
    sf::Vector2f first_pos_armour;
    sf::RectangleShape rectangle_armour[4];
    /**/

    ///Guns:ROF
    int ROF_level;
    sf::FloatRect ROF_button;
    sf::Vector2f first_pos_ROF;
    sf::RectangleShape rectangle_ROF[4];

    ///Guns:Cooling
    int Cooling_level;
    sf::FloatRect Cooling_button;
    sf::Vector2f first_pos_Cooling;
    sf::RectangleShape rectangle_Cooling[4];

    ///Rockets:Count
    int Count_level;
    sf::FloatRect Count_button;
    sf::Vector2f first_pos_Count;
    sf::RectangleShape rectangle_Count[4];

    ///Rockets:DMG
    int DMG_level;
    sf::FloatRect DMG_button;
    sf::Vector2f first_pos_DMG;
    sf::RectangleShape rectangle_DMG[4];

    ///Closing Button
    sf::FloatRect Closing_button;

    ///Streams for reading from files
    const std::string file_name;
    std::ifstream read_file;
    std::ofstream write_file;
    void save_changes();
    int string_int_converter(std::string );
    std::string int_string_converter(int );

    ///Writing out credits
    const std::string font_file;
    const std::string file_ScoreCredits;
    std::ifstream read_ScoreCredits;
    sf::Text text;
    sf::Font font;
    void intit_set_text();
    void load_credits_score();



    void make_rectangles(sf::Vector2f, sf::RectangleShape *);
    void draw_rectangles(sf::RenderWindow &);

    void Left_clicked(sf::Vector2i);

    void Upgrades_handler(sf::RenderWindow &);

    void reset_upgrades();
};


#endif
