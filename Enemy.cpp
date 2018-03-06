#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position_in, std::string file_in, float speed_in, bool direction_in ){

    position=position_in;
    texture_filename=file_in;
    movment_speed=speed_in;
    direction=direction_in;
    sprite_num=0;
    counter=0;

    enemy_texture.loadFromFile(texture_filename);
    for(int i=0; i<3; i++){
        enemy_sprite[i].setTexture(enemy_texture);
        enemy_sprite[i].setTextureRect(sf::IntRect(i*32, 0, 32, 32));
        enemy_sprite[i].setPosition(position);
    }

    collision.width=32;
    collision.height=32;
    set_Rect();

}

void Enemy::set_positions(){

    for(int i=0; i<3; i++){
        enemy_sprite[i].setPosition(position);
    }
    set_Rect();
}

void Enemy::rotate_blades(){

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

void Enemy::Enemy_move(){

    if(direction){
        position.y+=movment_speed;
        set_positions();
    }
    else{
        position.y-=movment_speed;
        set_positions();
    }
}

bool Enemy::Enemy_out(){
    if( position.y-16 >  my_mode.height-(32*game_scale_y/2) ){
        return true;
    }
    else{
        return false;
    }
}

void Enemy::set_Rect(){

    collision.left=position.x;
    collision.top=position.y;

}


void Enemy::Enemy_draw(sf::RenderWindow & window){
    //cout<<"sprite_num= "<<sprite_num<<endl;
    window.draw(enemy_sprite[sprite_num]);
}

void Enemy::Enemy_manage(sf::RenderWindow & window){

    rotate_blades();
    Enemy_move();
    Enemy_draw(window);
}
