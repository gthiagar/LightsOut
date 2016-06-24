#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game.h"
using std::string;


int main(){
    sf::RenderWindow window(sf::VideoMode(500, 500), string("Lights Out"));
    Game game(&window);
    while(window.isOpen()){
        game.read();
        game.update();
        game.draw();
    }
}
