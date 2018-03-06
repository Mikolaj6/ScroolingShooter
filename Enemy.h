#ifndef Enemy_hpp
#define Enemy_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

extern float game_scale_x;
extern float game_scale_y;

extern sf::VideoMode my_mode;

class Enemy{
private:
    std::string texture_filename;
    sf::Texture enemy_texture;
    sf::Sprite enemy_sprite[3];
    int counter;
    int sprite_num;
    void rotate_blades();

    void set_Rect();

    float health;               ///Not used yet!!!!!!
    float movment_speed;
    bool direction;

    void Enemy_move();
    void Enemy_draw(sf::RenderWindow & );
    void set_positions();

///From here starts future public all above is private
public:

    sf::Vector2f position;
    sf::FloatRect collision;                                    ///For collision detection remember enemy position starts at 0*0
    bool Enemy_out();
    Enemy(sf::Vector2f , std::string, float, bool =true );      ///starting position, filename for texture, speed value, direction (forward by default)
    void Enemy_manage(sf::RenderWindow & );

};


#endif // Enemy_hpp
