#include <sstream>
#include "Panel.h"

Panel::Panel(Player* wsk)
    :Panel_name("Resources/Panel.png"),
    font_file("Data/28 Days Later.ttf")
{
    wsk_Player=wsk;
    Panel_texture.loadFromFile(Panel_name);
    Panel_sprite.setTexture(Panel_texture);
    Panel_sprite.setScale((game_scale_x/2), (game_scale_y/2));
    Panel_sprite.setPosition(0, my_mode.height-((float)Panel_texture.getSize().y*(game_scale_y/2)));

    init_texts_font(my_mode.height-((float)Panel_texture.getSize().y*(game_scale_y/2)));

    overheat_shape.setPosition(237*game_scale_x/2, my_mode.height-((float)Panel_texture.getSize().y*(game_scale_y/2))+6*game_scale_y/2);
    overheat_shape.setFillColor(sf::Color::Green);
}

void Panel::init_texts_font(float panel_position_y){

    text_Score.setColor(sf::Color::White);
    text_MaxScore.setColor(sf::Color::White);
    text_Credits.setColor(sf::Color::White);

    if (!font.loadFromFile(font_file))
    {
        cout<<"Error loading fonts"<<endl;
    }
    text_Score.setFont(font);
    text_MaxScore.setFont(font);
    text_Credits.setFont(font);

    text_Score.setCharacterSize(9*game_scale_y/2);
    text_MaxScore.setCharacterSize(9*game_scale_y/2);
    text_Credits.setCharacterSize(9*game_scale_y/2);

    text_Score.setPosition(40*game_scale_x/2,4*game_scale_y/2+panel_position_y);
    text_MaxScore.setPosition(59*game_scale_x/2,18*game_scale_y/2+panel_position_y);
    text_Credits.setPosition(346*game_scale_x/2,4*game_scale_y/2+panel_position_y);

    text_Score.setString(int_string_converter(score));
    text_MaxScore.setString(int_string_converter(MaxScore));
    text_Credits.setString(int_string_converter(credits));
}


void Panel::draw_overheat(sf::RenderWindow & window){

    overheat_shape_dimens=sf::Vector2f(game_scale_x/2*43*(wsk_Player->Overheat_counter)/1000, game_scale_y/2*5);
    overheat_shape.setSize(overheat_shape_dimens);
    if(wsk_Player->Overheat_counter>600){
        overheat_shape.setFillColor(sf::Color::Green);
    }
    else if(wsk_Player->Overheat_counter<=600 && wsk_Player->Overheat_counter>400){
        overheat_shape.setFillColor(sf::Color::Yellow);
    }
    else{
        overheat_shape.setFillColor(sf::Color(255,165,0));
    }
    window.draw(overheat_shape);

}


void Panel::Panel_draw(sf::RenderWindow & window){

    window.draw(Panel_sprite);

    window.draw(text_Score);
    window.draw(text_MaxScore);
    window.draw(text_Credits);

    draw_overheat(window);

}


std::string Panel::int_string_converter(int number){
    std::string str_return;
    std::stringstream ss;
    ss.clear();
    ss << number;
    ss >> str_return;
    return str_return;
}
