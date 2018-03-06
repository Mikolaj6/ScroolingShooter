#ifndef Explosion_hpp
#define Explosion_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

class Explosion{
private:
    int arr_size;
    sf::Texture explosion_texture;
    std::string file_name;
    sf::Sprite* explosion_sprite;
    sf::Vector2f position;
    int current_sprite;
    int loops_per_frame;
    int counter;
    void step();

public:
    bool should_continue;
    Explosion(sf::Vector2f, std::string );       ///Starts with position of enemy, and name of the file with texture
    void explosion_manager(sf::RenderWindow & );

};

#endif // Explosion_hpp
