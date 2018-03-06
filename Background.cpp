#include "Background.h"

Background::Background()
    :counter(0),
    scrolling_speed(2),
    island_spacing(240)

    {
    //srand (time(NULL));
    water_texture.loadFromFile("Resources/water.png");
    water_texture.setRepeated(true);
    water_sprite.setTexture(water_texture);

    sprite_height = (my_mode.height+32);
    difference = 32;

    water_sprite.setTextureRect(sf::IntRect(0 , 0 , my_mode.width , sprite_height));
    water_sprite.setOrigin(sf::Vector2f(0,32));


    texture_1.loadFromFile("Resources/island1.png");
    texture_2.loadFromFile("Resources/island2.png");
    texture_3.loadFromFile("Resources/island3.png");
    texture_1.setRepeated(false);
    texture_2.setRepeated(false);
    texture_3.setRepeated(false);

    std::srand(std::time(NULL));

    ///Setting up initial positions of islands

    Island_init_positioning();

}

void Background::Island_movement(){

    for(int i=0; i<how_many_islands; i++){
        if(arr_islands[i].getPosition().y>my_mode.height){
            int switch_bla=rand()%3;
            switch(switch_bla){
            case 0:
                arr_islands[i].setTexture(texture_1);
                break;
            case 1:
                arr_islands[i].setTexture(texture_2);
                break;
            case 2:
                arr_islands[i].setTexture(texture_3);
                break;
            }

            int start_1_x=(rand()%((int)real_spacig-65))+(int)(i*real_spacig);
            int start_1_y=(rand()%(300))-365;
            arr_islands[i].setPosition((float)start_1_x, (float)start_1_y);
        }
        else{
            arr_islands[i].move(sf::Vector2f(0,scrolling_speed));
        }
    }

}

void Background::Island_init_positioning(){

    how_many_islands=my_mode.width/island_spacing;
    real_spacig=(float)my_mode.width/(float)how_many_islands;
    arr_islands = new sf::Sprite [how_many_islands];

    for(int i=0; i<how_many_islands; i++){

        int switch_bla=rand()%3;
        switch(switch_bla){
        case 0:
            arr_islands[i].setTexture(texture_1);
            break;
        case 1:
            arr_islands[i].setTexture(texture_2);
            break;
        case 2:
            arr_islands[i].setTexture(texture_3);
            break;
        }

        int start_1_x=(rand()%((int)real_spacig-65))+(int)(i*real_spacig);
        int start_1_y=(rand()%(my_mode.height+600))-680;
        arr_islands[i].setPosition((float)start_1_x, (float)start_1_y);
    }

}



void Background::Background_movement(){
    const float maximum = difference;
    if(maximum>counter){
        water_sprite.move(sf::Vector2f(0,scrolling_speed));
        counter+=scrolling_speed;
    }
    else{
        water_sprite.setPosition(sf::Vector2f(0,0));
        counter=0;
        water_sprite.move(sf::Vector2f(0,scrolling_speed));
        counter+=scrolling_speed;
    }
}

void Background::draw_everything(sf::RenderWindow& window){
    Background_movement();
    Island_movement();
    window.draw(water_sprite);
    for(int i=0; i<how_many_islands; i++){
        window.draw(arr_islands[i]);
        //cout<<"Island_"<<i<<"_x = "<<arr_islands[i].getPosition().x<<"Island_"<<i<<"_x = "<<arr_islands[i].getPosition().y<<endl;
    }
}

Background::~Background(){
    delete [] arr_islands;
}
