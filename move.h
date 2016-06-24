#ifndef __MOVE_H__
#define __MOVE_H__
#include <SFML/Graphics.hpp>

class Move{
public:
    int x;
    int y;
    Move();
    Move(int x, int y);
    Move(const sf::Vector2i &vec);
    int getRow();
    int getColumn();
    void operator=(const Move& mv);
    bool operator!=(const Move & mv);
};

#endif // __MOVE_H__
