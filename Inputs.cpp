#include "inputs.h"
#include "Game.h"

inputs::inputs(Game *wsk_input, upgrades *wsk_upgrades_input, Player *player_wsk){

    wsk=wsk_input;
    wsk_upgrades=wsk_upgrades_input;
    wsk_player=player_wsk;

}


void inputs::get_events(sf::RenderWindow & window){

    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed){

                if(event.key.code == sf::Keyboard::Escape){

                    if(game_state==1 || game_state==2){
                        cout<<"Exited through escape"<<endl;
                        window.close();
                    }
                    else if(game_state==3){
                        game_state=1;
                        wsk_player->Player_Reset();
                    }

                }
                if(event.key.code == sf::Keyboard::Up && game_state==1){
                    menu_arrows(wsk, this, 8);
                }
                if(event.key.code == sf::Keyboard::Down && game_state==1){
                    menu_arrows(wsk, this, 2);
                }
                if(event.key.code == sf::Keyboard::Left && game_state==1){
                    menu_arrows(wsk, this, 4);
                }
                if(event.key.code == sf::Keyboard::Right && game_state==1){
                    menu_arrows(wsk, this, 6);
                }
                if(event.key.code == sf::Keyboard::Return){ ///When Enter is pressed

                    if(wsk->menu_position==4){
                        wsk_upgrades->reset_upgrades();
                    }
                    else if(wsk->menu_position==2){
                        mode_changer(wsk);
                    }
                    else{
                        mode_changer(wsk);
                    }

                }
                if(event.key.code == sf::Keyboard::P){  ///Pausing game

                    if(game_state==3){
                        game_state=4;
                    }
                    else if(game_state==4){
                        game_state=3;
                    }

                }

                if(event.key.code== sf::Keyboard::Space){
                    wsk_player->space_pressed=true;
                }

            }   ///End of key pressed

            if (event.type == sf::Event::KeyReleased){

                if(event.key.code== sf::Keyboard::Space){
                    wsk_player->space_pressed=false;
                }

            }

            if (event.type == sf::Event::MouseButtonPressed){

                if(event.mouseButton.button == sf::Mouse::Left && game_state==2){
                    wsk_upgrades->Left_clicked(sf::Mouse::getPosition(window));
                }

                //cout<<sf::Mouse::getPosition(window).x<<"    "<<sf::Mouse::getPosition(window).y<<endl;
            }


        }


}
