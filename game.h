#ifndef __GAME_H__
#define __GAME_H__
#include <SFML/Graphics.hpp>
#include "move.h"

class Game{
public:
    sf::RenderWindow *window;
    Move mouseMove;
    Move oldMove;
    bool lights[5][5];
    void read();
    void update();
    void draw();
    Game(sf::RenderWindow * win);
};

#endif // __GAME_H__
