#include "move.h"

Move::Move(){}
Move::Move(int x, int y) : x(x), y(y) {}

Move::Move(const sf::Vector2i & vec){
    x = vec.x;
    y = vec.y;
}

int Move::getRow(){
    return x/100;
}

int Move::getColumn(){
    return y/100;
}

void Move::operator=(const Move& mv){
   x = mv.x;
   y = mv.y;
}

bool Move::operator!=(const Move & mv){
    return !((x == mv.x) && (y == mv.y));
}
