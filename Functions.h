#ifndef Functions_hpp
#define Functions_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Inputs.h"

using std::cout;
using std::endl;


class Game;
class inputs;


void menu_arrows(Game *, inputs *, int );

void mode_changer(Game *);


#endif
