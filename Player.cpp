#include <math.h>
#include "Player.h"


Player::Player(upgrades *wsk)
    :player_position(my_mode.width/2, my_mode.height/3),
    bottom_line((float)my_mode.height-(32*game_scale_y/2)),
    right_line((float)my_mode.width),
    player_file_name("Resources/player.png")

{

    wsk_upgrades=wsk;
    counter=0;
    sprite_num=0;
    space_pressed=false;
    ROF_counter=100;
    Overheat_counter=1000;
    can_fire=false;

    player_texture.loadFromFile(player_file_name);

    for(int i=0; i<3; i++){
        player_sprite[i].setTexture(player_texture);
        player_sprite[i].setTextureRect(sf::IntRect(i*65, 0, 65, 65));
        player_sprite[i].setOrigin(33,33);
        //player_sprite[i].setPosition(100,100);
    }

    set_regeneration();
    set_Act_ROF();
}

void Player::PBull_manager_P(sf::RenderWindow & window){

    set_regeneration();
    set_Act_ROF();

    ROF_counter+=Act_ROF;

    if(jammed==true && Overheat_counter>400){
        jammed=false;
    }

    if(space_pressed && ROF_counter>100 && Overheat_counter>0 && jammed==false){    ///Player wants to shot guns

        PBull_belt.push_back(new PBullet(player_position));

        ROF_counter=0;

        if(Overheat_counter-180 < 0){
            Overheat_counter=0;
            jammed=true;
        }
        else{
            Overheat_counter-=180;
        }

    }

    if(Overheat_counter+Overheat_regeneration>1000){
        Overheat_counter=1000;
    }
    else{
        Overheat_counter+=Overheat_regeneration;
    }


    for(int i=0; i<PBull_belt.size(); i++){                                         ///Checkups for every bullet
        PBull_belt[i]->PBullet_manage(window);
    }

    del_off_PBull();                                                                ///deleting off screen bullets

}

void Player::set_Act_ROF(){

    switch(wsk_upgrades->ROF_level){
    case 0:
        Act_ROF=2.5;
        break;
    case 1:
        Act_ROF=3.63;
        break;
    case 2:
        Act_ROF=5.26;
        break;
    case 3:
        Act_ROF=7.62;
        break;
    case 4:
        Act_ROF=11.05;
        break;
    }
}

void Player::set_regeneration(){

    switch(wsk_upgrades->Cooling_level){
    case 0:
        Overheat_regeneration=2.2;
        break;
    case 1:
        Overheat_regeneration=3;
        break;
    case 2:
        Overheat_regeneration=4;
        break;
    case 3:
        Overheat_regeneration=5.6;
        break;
    case 4:
        Overheat_regeneration=7.8;
        break;
    }
}

void Player::set_speed(){

    switch(wsk_upgrades->Speed_level){
    case 0:
        Speed_actual=1.5;
        break;
    case 1:
        Speed_actual=2.025;
        break;
    case 2:
        Speed_actual=2.73;
        break;
    case 3:
        Speed_actual=3.7;
        break;
    case 4:
        Speed_actual=5;
        break;
    }
}


void Player::del_off_PBull(){

    for(int i=0; i<PBull_belt.size(); i++){

        if(PBull_belt[i]->PBull_out()){
            delete PBull_belt[i];
            PBull_belt.erase(PBull_belt.begin()+i);
            i=0;
        }

    }
}

void Player::delete_bullet(int num){

    delete PBull_belt[num];
    PBull_belt.erase(PBull_belt.begin()+num);
}


void Player::Player_draw(sf::RenderWindow & window){

    window.draw(player_sprite[sprite_num]);

}


void Player::Player_ShangeSprites(){

    counter++;
    if(counter<25){
        sprite_num=0;
    }
    else if(counter>=25 && counter<50){
        sprite_num=1;
    }
    else if(counter>=50 && counter<75){
        sprite_num=2;
    }
    else{
        counter=0;
    }

}

inline float Player::get_top(){
    return (player_position.y-32);
}
inline float Player::get_bottom(){
    return (player_position.y+32);
}
inline float Player::get_left(){
    return (player_position.x-32);
}
inline float Player::get_right(){
    return (player_position.x+32);
}


void Player::Player_management(sf::RenderWindow & window){

    Player_ShangeSprites();
    Player_move(window);
    Player_draw(window);

}

void Player::Player_move(sf::RenderWindow & window){

    set_speed();
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    double diff_x=(double)mouse_position.x-(double)player_position.x;
    double diff_y=(double)mouse_position.y-(double)player_position.y;
    double pita = (diff_x*diff_x)+(diff_y*diff_y);
    float distance = (float)pow( pita , 0.5 );

    float delta_x = ((float)diff_x*(float)(Speed_actual))/(distance);
    float delta_y =((float)diff_y*(float)(Speed_actual))/(distance);


    if( (float)Speed_actual >= distance){  ///Short (just jump)
        player_position.x=(float)mouse_position.x;
        player_position.y=(float)mouse_position.y;
    }
    else{                                               ///Movement

        if( (get_top()+delta_y) < 0 ){                      ///Vertical
            player_position.y=32;
        }
        else if( (get_bottom()+delta_y) > bottom_line ){
            player_position.y=bottom_line-32;
        }
        else{
            player_position.y += delta_y;
        }

        if( (get_left()+delta_x) < 0 ){                      ///Horizontal
            player_position.x=32;
        }
        else if( (get_right()+delta_x) > right_line ){
            player_position.x=right_line-32;
        }
        else{
            player_position.x += delta_x;
        }

    }


    for(int i=0; i<3; i++){
        player_sprite[i].setPosition(player_position);
    }

}


void Player::Player_Reset(){

    player_position = sf::Vector2f(my_mode.width/2, my_mode.height/3);

    for(int i=0; i<PBull_belt.size(); i++){
        delete PBull_belt[i];
    }
    PBull_belt.clear();

    ROF_counter=100;
    Overheat_counter=1000;
}
