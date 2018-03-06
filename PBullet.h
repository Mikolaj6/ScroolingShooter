#ifndef PBullet_hpp
#define PBullet_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

//#include "Player.h"

using std::cout;
using std::endl;

class PBullet{
public:

    float bullet_speed;

    sf::Vector2f position;

    sf::Texture PBull_texture;
    sf::Sprite PBull_sprite;
    const std::string PBull_filename;

    sf::FloatRect collision;                    ///For collision detection
    void set_Rect();

    PBullet(sf::Vector2f );
    PBullet();

    void PBullet_move();

    void PBullet_draw(sf::RenderWindow & );

    void PBullet_manage(sf::RenderWindow & );

    bool PBull_out();

};


#endif // PBullet_hpp
