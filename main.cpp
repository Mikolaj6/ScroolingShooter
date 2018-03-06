#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <time.h>

#include "Inputs.h"
#include "Game.h"
#include "Functions.h"
#include "Upgrades.h"
#include "Background.h"
#include "Panel.h"
#include "Player.h"
#include "Enemy_handler.h"

using std::cout;
using std::endl;



sf::VideoMode my_mode;  ///Video mode everyone uses

int game_state=1;   ///Values from 1-4  1=Menu, 2=Upgrades, 3=level, 4=PAUSE


int score=0;
int MaxScore=0;
int credits=0;


float game_scale_x;
float game_scale_y;



int main()
{


    my_mode=sf::VideoMode::getDesktopMode();
    //my_mode.width=800;
    //my_mode.height=640;
    //sf::RenderWindow window(my_mode, "1940");
    sf::RenderWindow window(my_mode, "1940", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    ///Setting scale


    game_scale_x=(float)my_mode.width/192;
    game_scale_y=(float)my_mode.height/108;
    ///End of setting scale

    //cout<<"game_scale_x= "<<game_scale_x<<endl;
    //cout<<"game_scale_y= "<<game_scale_y<<endl;

    Game main_game;         ///Core Game object

    upgrades upgrades_class(&main_game);        ///Manages upgrades

    Background main_background;                 ///Background management


    Player main_Player(&upgrades_class);        ///Player management

    Panel main_panel(&main_Player);                           ///Panel management

    Enemy_handler main_handler(&main_Player);

    inputs main_inputs(&main_game, &upgrades_class, &main_Player);    ///Input object

    while (window.isOpen())
    {

        main_inputs.get_events(window);



        window.clear();

        ///Now drawing time

        switch (game_state){
        case 1:
            main_game.Menu_handling(window);
            break;
        case 2:
            upgrades_class.Upgrades_handler(window);
            break;
        case 3:
            main_background.draw_everything(window);
            main_Player.Player_management(window);
            main_Player.PBull_manager_P(window);
            main_handler.manage_enemies(window);

            main_panel.Panel_draw(window);

            break;
        case 4:
            main_game.draw_Pause(window);
            break;
        }


        window.display();
    }


    return 0;
}
