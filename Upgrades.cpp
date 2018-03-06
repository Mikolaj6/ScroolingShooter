#include <sstream>
#include "Upgrades.h"


upgrades::upgrades(Game *wsk)
    :Speed_button(game_scale_x*24, game_scale_y*20, game_scale_x*7, game_scale_y*5),
    first_pos_speed(64,18),
    Armour_button(game_scale_x*90, game_scale_y*20, game_scale_x*7, game_scale_y*5),
    first_pos_armour(144,18),
    ROF_button(game_scale_x*24, game_scale_y*49, game_scale_x*7, game_scale_y*5),
    first_pos_ROF(54,47),
    Cooling_button(game_scale_x*90, game_scale_y*49, game_scale_x*7, game_scale_y*5),
    first_pos_Cooling(142,47),
    Count_button(game_scale_x*24, game_scale_y*78, game_scale_x*7, game_scale_y*5),
    first_pos_Count(70,76),
    DMG_button(game_scale_x*90, game_scale_y*78, game_scale_x*7, game_scale_y*5),
    first_pos_DMG(120,76),
    Closing_button((float)game_scale_x*120, (float)game_scale_y*90, (float)game_scale_x*37, (float)game_scale_y*13),
    file_name("Data/Upgrades.txt"),
    font_file("Data/28 Days Later.ttf"),
    file_ScoreCredits("Data/Credits and max score.txt")

{

    this->wsk=wsk;

    upgrades_texture.loadFromFile("Resources/Upgrades.png");


    Upgrades_sprite.setTexture(upgrades_texture);
    Upgrades_sprite.setTextureRect(sf::IntRect(0, 0, 192, 108));

    Upgrades_sprite.setScale(game_scale_x, game_scale_y);


    ///Reading stats from file
    read_file.open(file_name);
    if(read_file.is_open()){
        int i=0;
        while(!read_file.eof()){
            std::string num;
            getline(read_file, num);

            switch(i){
            case 0:
                Speed_level=string_int_converter( num );
                break;
            case 1:
                Armour_level=string_int_converter( num );
                break;

            case 2:
                ROF_level=string_int_converter( num );
                break;

            case 3:
                Cooling_level=string_int_converter( num );
                break;

            case 4:
                Count_level=string_int_converter( num );
                break;

            case 5:
                DMG_level=string_int_converter( num );
                break;
            }
            i++;
        }
    }
    else{
        cout<<"Error opening file..."<<endl;
    }
    read_file.close();
    ///Ending reading stats from file


    ///Credits and score initialization
    load_credits_score();
    intit_set_text();


    ///Plane:Speed management
    make_rectangles(first_pos_speed, rectangle_speed);

    ///Plane:Armour
    make_rectangles(first_pos_armour, rectangle_armour);

    ///Guns:ROF
    make_rectangles(first_pos_ROF, rectangle_ROF);

    ///Guns:Cooling
    make_rectangles(first_pos_Cooling, rectangle_Cooling);

    ///Rockets:Count
    make_rectangles(first_pos_Count, rectangle_Count);

    ///Rockets:DMG
    make_rectangles(first_pos_DMG, rectangle_DMG);


}

void upgrades::save_changes(){
    write_file.open(file_name);
    write_file.seekp(0);
    if(write_file.is_open()){

        for(int i=0; i<6; i++){

            switch(i){
            case 0:
                write_file << Speed_level << "\n";
                //cout<<"i= "<<i<<"Speed_level= "<<Speed_level<<endl;
                break;
            case 1:
                write_file << Armour_level << "\n";
                //cout<<"i= "<<i<<"Armour_level= "<<Armour_level<<endl;
                break;
            case 2:
                write_file << ROF_level << "\n";
                //cout<<"i= "<<i<<"ROF_level= "<<ROF_level<<endl;
                break;

            case 3:
                write_file << Cooling_level << "\n";
                //cout<<"i= "<<i<<"Cooling_level= "<<Cooling_level<<endl;
                break;

            case 4:
                write_file << Count_level << "\n";
                //cout<<"i= "<<i<<"Count_level= "<<Count_level<<endl;
                break;

            case 5:
                write_file << DMG_level << "\n";
                //cout<<"i= "<<i<<"DMG_level= "<<DMG_level<<endl;
                break;
            }

        }

    }
    else{
        cout<<"Error writing to the file..."<<endl;
    }
    write_file.close();

}


int upgrades::string_int_converter(std::string s){
    int int_return=0;
    std::stringstream ss;
    ss.clear();
    ss << s;
    ss >> int_return;
    return int_return;
}


void upgrades::Upgrades_handler(sf::RenderWindow & window){

    window.draw(Upgrades_sprite);
    draw_rectangles(window);

    ///Credits
    text.setString(int_string_converter(credits));
    window.draw(text);


}


void upgrades::Left_clicked(sf::Vector2i mouse_pos){

    if(Speed_button.contains((sf::Vector2f)mouse_pos)){

        if(Speed_level<4){
            Speed_level++;
            save_changes();
        }
    }
    else if(Armour_button.contains((sf::Vector2f)mouse_pos)){
        if(Armour_level<4){
            Armour_level++;
            save_changes();
        }
    }
    else if(ROF_button.contains((sf::Vector2f)mouse_pos)){
        if(ROF_level<4){
            ROF_level++;
            save_changes();
        }
    }
    else if(Cooling_button.contains((sf::Vector2f)mouse_pos)){
        if(Cooling_level<4){
            Cooling_level++;
            save_changes();
        }
    }
    else if(Count_button.contains((sf::Vector2f)mouse_pos)){
        if(Count_level<4){
            Count_level++;
            save_changes();
        }
    }
    else if(DMG_button.contains((sf::Vector2f)mouse_pos)){
        if(DMG_level<4){
            DMG_level++;
            save_changes();
        }
    }
    else if(Closing_button.contains((sf::Vector2f)mouse_pos)){
        mode_changer(wsk);
    }

}

void upgrades::make_rectangles(sf::Vector2f begining, sf::RectangleShape *rectangles){

    for(int i=0; i<4; i++){
        rectangles[i].setSize(sf::Vector2f(2*game_scale_x, 9*game_scale_y));
        rectangles[i].setPosition( ((begining.x*game_scale_x)+(4*game_scale_x*i)), (begining.y*game_scale_y) );
        rectangles[i].setFillColor(sf::Color::Red);
    }
}

void upgrades::draw_rectangles(sf::RenderWindow & window){

    for(int i=0; i<Speed_level; i++){
        //cout<<"rectangle_speed["<<i<<"]: X="<<rectangle_speed[i].getPosition().x<<" Y="<< rectangle_speed[i].getPosition().y<<endl;
        window.draw(rectangle_speed[i]);
    }
    for(int i=0; i<Armour_level; i++){
        //cout<<"rectangle_armour["<<i<<"]: X="<<rectangle_armour[i].getPosition().x<<" Y="<< rectangle_armour[i].getPosition().y<<endl;
        window.draw(rectangle_armour[i]);
    }
    for(int i=0; i<ROF_level; i++){
        //cout<<"rectangle_ROF["<<i<<"]: X="<<rectangle_ROF[i].getPosition().x<<" Y="<< rectangle_ROF[i].getPosition().y<<endl;
        window.draw(rectangle_ROF[i]);
    }
    for(int i=0; i<Cooling_level; i++){
        //cout<<"rectangle_Cooling["<<i<<"]: X="<<rectangle_Cooling[i].getPosition().x<<" Y="<< rectangle_Cooling[i].getPosition().y<<endl;
        window.draw(rectangle_Cooling[i]);
    }
    for(int i=0; i<Count_level; i++){
        //cout<<"rectangle_Count["<<i<<"]: X="<<rectangle_Count[i].getPosition().x<<" Y="<< rectangle_Count[i].getPosition().y<<endl;
        window.draw(rectangle_Count[i]);
    }
    for(int i=0; i<DMG_level; i++){
        //cout<<"rectangle_DMG["<<i<<"]: X="<<rectangle_DMG[i].getPosition().x<<" Y="<< rectangle_DMG[i].getPosition().y<<endl;
        window.draw(rectangle_DMG[i]);
    }
}

void upgrades::reset_upgrades(){

    Speed_level=0;
    Armour_level=0;
    ROF_level=0;
    Cooling_level=0;
    Count_level=0;
    DMG_level=0;

    save_changes();

}


void upgrades::intit_set_text(){

    text.setColor(sf::Color::White);
    if (!font.loadFromFile(font_file))
    {
        cout<<"Error loading fonts"<<endl;
    }
    text.setFont(font);

    text.setPosition(81*game_scale_x,92*game_scale_y);
    text.setCharacterSize(9*game_scale_y);

}


void upgrades::load_credits_score(){

    read_ScoreCredits.open(file_ScoreCredits);

    if(read_ScoreCredits.is_open()){
        int i=0;
        while(!read_ScoreCredits.eof()){
            std::string result;
            getline(read_ScoreCredits,result);
            switch(i){
            case 0:
                MaxScore=string_int_converter(result);
                break;
            case 1:
                credits=string_int_converter(result);
                break;
            }
            i++;
        }
    }
    else{
        cout<<"Error loading scores and credits"<<endl;
    }


    read_ScoreCredits.close();
}

std::string upgrades::int_string_converter(int number){
    std::string str_return;
    std::stringstream ss;
    ss.clear();
    ss << number;
    ss >> str_return;
    return str_return;
}

