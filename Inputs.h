#ifndef inputs_hpp
#define inputs_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Functions.h"
#include "Upgrades.h"
#include "Player.h"

using std::cout;
using std::endl;

class Game;
class upgrades;
class Player;


//int game_state;


class inputs{
public:


    sf::Event event;

    Game *wsk;
    upgrades *wsk_upgrades;
    Player *wsk_player;

    inputs(Game *, upgrades *, Player *);

    void get_events(sf::RenderWindow &);



};


#endif // inputs_hpp
