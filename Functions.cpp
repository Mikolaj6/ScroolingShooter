#include "Functions.h"

void menu_arrows(Game *wsk_game, inputs *wsk_inputs, int direction){

    if(wsk_game->menu_position==1 && direction==2){
        wsk_game->menu_position=3;
    }
    if(wsk_game->menu_position==1 && direction==6){
        wsk_game->menu_position=2;
    }
    if(wsk_game->menu_position==2 && direction==4){
        wsk_game->menu_position=1;
    }
    if(wsk_game->menu_position==2 && direction==2){
        wsk_game->menu_position=4;
    }
    if(wsk_game->menu_position==3 && direction==8){
        wsk_game->menu_position=1;
    }
    if(wsk_game->menu_position==3 && direction==6){
        wsk_game->menu_position=4;
    }
    if(wsk_game->menu_position==4 && direction==4){
        wsk_game->menu_position=3;
    }
    if(wsk_game->menu_position==4 && direction==8){
        wsk_game->menu_position=2;
    }
}

void mode_changer(Game *wsk_game){

    if(game_state==1 && wsk_game->menu_position==1){
        wsk_game->menu_position=1;
        game_state=2;
        //cout<<"game_state= "<<game_state<<endl;
    }
    else if(game_state==1 && wsk_game->menu_position==2){
        wsk_game->menu_position=1;
        game_state=3;
        //cout<<"game_state= "<<game_state<<endl;
    }
    else if(game_state==2){
        game_state=1;
    }

}

