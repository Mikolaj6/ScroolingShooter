#include "Game.h"

Game::Game(){

    menu_texture.loadFromFile("Resources/Menu.png");

    Menu_sprite_1.setTexture(menu_texture);
    Menu_sprite_1.setTextureRect(sf::IntRect(0, 0, 192, 108));
    Menu_sprite_1.setScale(my_mode.width/192, my_mode.height/108);

    Menu_sprite_2.setTexture(menu_texture);
    Menu_sprite_2.setTextureRect(sf::IntRect(192, 0, 192, 108));
    Menu_sprite_2.setScale(my_mode.width/192, my_mode.height/108);

    Menu_sprite_3.setTexture(menu_texture);
    Menu_sprite_3.setTextureRect(sf::IntRect(0, 108, 192, 108));
    Menu_sprite_3.setScale(my_mode.width/192, my_mode.height/108);

    Menu_sprite_4.setTexture(menu_texture);
    Menu_sprite_4.setTextureRect(sf::IntRect(192, 108, 192, 108));
    Menu_sprite_4.setScale(my_mode.width/192, my_mode.height/108);

    Pause_texture.loadFromFile("Resources/Pause.png");
    Pause_sprite.setTexture(Pause_texture);
    Pause_sprite.setScale(game_scale_x, game_scale_y);


    game_state=1;
    menu_position=1;
}

void Game::Menu_handling(sf::RenderWindow & window){


    switch(menu_position){
        case 1:
            window.draw(Menu_sprite_1);
            break;
        case 2:
            window.draw(Menu_sprite_2);
            break;
        case 3:
            window.draw(Menu_sprite_3);
            break;
        case 4:
            window.draw(Menu_sprite_4);
            break;
    }


}

void Game::draw_Pause(sf::RenderWindow & window){

    window.draw(Pause_sprite);

}

