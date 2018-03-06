#ifndef Enemy_handler_hpp
#define Enemy_handler_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Enemy.h"
#include "Player.h"
#include "Explosion.h"

using std::cout;
using std::endl;

class Explosion;
class Enemy;
class Player;

extern sf::VideoMode my_mode;

class Enemy_handler{
private:

    std::vector <Enemy *> Enemy_1_V;
    float counter_1;
    float limit_1;
    float jump_1;
    bool Enemy_1_numbers();

    Player * player_wsk;
    void del_off_Enem_1();
    void scan_for_hits();
    void delete_Enemy(int );

    ///Explosion handling
    std::vector <Explosion *> Explosion_V;
    void manage_explosions(sf::RenderWindow & );

public:
    Enemy_handler(Player * );
    void manage_enemies(sf::RenderWindow & );


};


#endif
