#include "PBullet.h"


PBullet::PBullet(sf::Vector2f player_pos)
    :PBull_filename("Resources/bullet.png"),
    bullet_speed(8)

{

    PBull_texture.loadFromFile(PBull_filename);
    PBull_sprite.setTexture(PBull_texture);
    PBull_sprite.setOrigin(15,15);                  /// 15 - 1 - 16 horizontal and vertical
    position=player_pos;
    PBull_sprite.setPosition(position);

    collision.width=9;
    collision.height=20;
    set_Rect();

}


PBullet::PBullet(){             ///Testing constructor

    cout<<"blablabla"<<endl;

}


void PBullet::PBullet_move(){

    position.y-=bullet_speed;
    PBull_sprite.setPosition(position);
    set_Rect();

}


void PBullet::set_Rect(){

    collision.left=position.x-4;
    collision.top=position.y-8;

}


void PBullet::PBullet_draw(sf::RenderWindow & window){

    window.draw(PBull_sprite);

}


void PBullet::PBullet_manage(sf::RenderWindow & window){

    PBullet_move();
    PBullet_draw(window);

}

bool PBullet::PBull_out(){

    if( position.y+16 < 0 ){
        return true;
    }
    else{
        return false;
    }
}
