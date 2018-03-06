#ifndef Panel_hpp
#define Panel_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"

using std::cout;
using std::endl;

extern sf::VideoMode my_mode;

extern float game_scale_x;
extern float game_scale_y;

extern int score;
extern int MaxScore;
extern int credits;

class Player;

class Panel{
public:

    Player* wsk_Player;

    sf::Texture Panel_texture;
    sf::Sprite Panel_sprite;
    const std::string Panel_name;

    Panel(Player* );
    void Panel_draw(sf::RenderWindow &);

    sf::Font font;
    const std::string font_file;

    sf::Text text_Score;
    std::string string_Score;

    sf::Text text_MaxScore;
    std::string string_MaxScore;

    sf::Text text_Credits;
    std::string string_Credits;

    sf::RectangleShape overheat_shape;
    sf::Vector2f overheat_shape_dimens;
    void draw_overheat(sf::RenderWindow &);



    void init_texts_font(float );

    std::string int_string_converter(int );

};


#endif // Panel_hpp
