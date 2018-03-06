#include "Explosion.h"

Explosion::Explosion(sf::Vector2f given_pos, std::string file_name_in){

    position=given_pos;
    file_name=file_name_in;
    explosion_texture.loadFromFile(file_name_in);

    if(explosion_texture.getSize().y==65){
        arr_size=7;
    }
    else{
        arr_size=6;
    }
    explosion_sprite = new sf::Sprite[arr_size];

    for(int i=0; i<arr_size; i++){

        if(explosion_texture.getSize().y==65){
            explosion_sprite[i].setOrigin(32,32);
            explosion_sprite[i].setTexture(explosion_texture);
            explosion_sprite[i].setTextureRect(sf::IntRect(i*65, 0, 65, 65));
            explosion_sprite[i].setPosition(position);
        }
        else{
            explosion_sprite[i].setTexture(explosion_texture);
            explosion_sprite[i].setTextureRect(sf::IntRect(i*32, 0, 32, 32));
            explosion_sprite[i].setPosition(position);
        }
    }
    loops_per_frame=10;
    counter=0;
    current_sprite=0;
    should_continue=true;
}


void Explosion::step(){

    counter++;
    if(loops_per_frame==counter){
        counter=0;
        current_sprite++;
    }
    if(current_sprite>=6 && arr_size==6){
        should_continue=false;
    }
    if(current_sprite>=7 && arr_size==7){
        should_continue=false;
    }
}


void Explosion::explosion_manager(sf::RenderWindow & window){

    step();
    if(should_continue){
        cout<<"current_sprite= "<<current_sprite<<endl;
        window.draw(explosion_sprite[current_sprite]);
    }
}
