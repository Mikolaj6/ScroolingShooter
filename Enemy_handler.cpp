#include "Enemy_handler.h"

Enemy_handler::Enemy_handler(Player * wsk){

    std::srand(std::time(NULL));

    counter_1=0;
    limit_1=100;
    jump_1=5;

    player_wsk=wsk;
}

bool Enemy_handler::Enemy_1_numbers(){

    counter_1+=jump_1;

    if(counter_1>limit_1){
        counter_1=0;

        if(jump_1<15){
            jump_1+=(1/jump_1/2.2);
        }
        else if(jump_1>=15 && jump_1<30){
            jump_1+=(1/jump_1/1.5);
        }
        else if(jump_1>=30 && jump_1<50){
            jump_1+=(1/jump_1/1.2);
        }else{
            jump_1+=(1/jump_1*1.4);
        }
        return true;

    }
    else{
        return false;    ///When enemy cannot spawn
    }

}

void Enemy_handler::scan_for_hits(){

    for(int i=0; i<Enemy_1_V.size(); i++){

        for(int j=0; j<player_wsk->PBull_belt.size(); j++){

            if( Enemy_1_V[i]->collision.intersects( player_wsk->PBull_belt[j]->collision ) ){

                sf::Vector2f temp = Enemy_1_V[i]->position;
                delete_Enemy(i);
                player_wsk->delete_bullet(j);
                Explosion_V.push_back(new Explosion(temp, "Resources/explosion1.png"));

            }
        }


    }

}


void Enemy_handler::manage_explosions(sf::RenderWindow & window){

    for(int i=0; i<Explosion_V.size(); i++){

        Explosion_V[i]->explosion_manager(window);

        if( !Explosion_V[i]->should_continue ){
            delete Explosion_V[i];
            Explosion_V.erase(Explosion_V.begin()+i);
        }
    }

}


void Enemy_handler::manage_enemies(sf::RenderWindow & window){

    if(Enemy_1_numbers()){
        Enemy_1_V.push_back(new Enemy( sf::Vector2f((rand()%my_mode.width),-16) , "Resources/enemy1.png", 5));
    }

    del_off_Enem_1();

    scan_for_hits();

    /**/
    for(int i=0; i<Enemy_1_V.size(); i++){
        Enemy_1_V[i]->Enemy_manage(window);
    }
    manage_explosions(window);

}

void Enemy_handler::del_off_Enem_1(){

    for(int i=0; i<Enemy_1_V.size(); i++){

        if(Enemy_1_V[i]->Enemy_out()){
            delete Enemy_1_V[i];
            Enemy_1_V.erase(Enemy_1_V.begin()+i);
            i=0;
        }
    }
}

void Enemy_handler::delete_Enemy(int num){

    delete Enemy_1_V[num];
    Enemy_1_V.erase(Enemy_1_V.begin()+num);

}

