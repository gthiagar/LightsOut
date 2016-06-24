#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

void Game::read(){
    sf::Event event;
    while(window->pollEvent(event)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouseMove = Move(sf::Mouse::getPosition(*window));
        }

        if(event.type == sf::Event::Closed){
            window->close();
        }
    }
}
void Game::update(){
    if(oldMove != mouseMove){
        int row = mouseMove.getRow(), column = mouseMove.getColumn();
        //std::cout << row  << " " << column << std::endl;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i == row && j == column){
                    lights[row][column] = !lights[row][column];
                    if(row - 1 >= 0){
                        lights[row-1][column] = !lights[row-1][column];
                    }
                    if(row + 1 < 5){
                        lights[row+1][column] = !lights[row+1][column];
                    }
                    if(column - 1 >= 0){
                        lights[row][column-1] = !lights[row][column-1];
                    }
                    if(column + 1 < 5){
                        lights[row][column+1] = !lights[row][column+1];
                    }
                }
            }
        }
        oldMove = mouseMove;
    }
    bool isGameOver = true;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            isGameOver = isGameOver && lights[i][j];
        }
    }
    while(isGameOver){
        static sf::RenderWindow restartWindow(sf::VideoMode(500, 500), "Do you want to play?");
        sf::Event event;
        RectangleShape restartButton(Vector2f(200, 200));
        restartButton.setPosition(Vector2f(150, 150));
        restartButton.setFillColor(Color(50, 50, 120));
        Font font;
        if(!font.loadFromFile(std::string("arial.ttf"))){
            return ;
        }
        Text restartText(std::string("Restart"), font, 10);
        restartText.setPosition(Vector2f(235, 235));

        while(restartWindow.pollEvent(event)){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                Vector2i position = sf::Mouse::getPosition(restartWindow);
                if(position.x >= 150 && position.x <= 350 &&
                   position.y >= 150 && position.y <= 350){
                    // Reset Game
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 5; j++){
                            lights[i][j] = static_cast<int>(rand()) % 2;
                        }
                    }
                    // Break Out of loop
                    restartWindow.close();
                    isGameOver = false;
                }
            }
            if(event.type == sf::Event::Closed){
                restartWindow.close();
                window->close();
            }
            restartWindow.clear(Color(0, 0, 0));
            restartWindow.draw(restartButton);
            restartWindow.draw(restartText);
            restartWindow.display();
        }
    }
}
void Game::draw(){
    window->clear();
    for(int i = 0; i < 5; i++){
        for(int j = 0 ; j < 5; j++){
            sf::Color fillColor(0,100, 20);
            sf::Color outlineColor(0, 0, 0);
            if(lights[i][j]){
                fillColor.b += 100;
            }
            else{
                fillColor.r = 60;
            }
            sf::RectangleShape rect(sf::Vector2f(100, 100));
            rect.setPosition(sf::Vector2f(i*100, j*100));
            rect.setFillColor(fillColor);
            rect.setOutlineColor(outlineColor);
            rect.setOutlineThickness(1);
            window->draw(rect);
        }
    }
    window->display();
}

Game::Game(sf::RenderWindow *win) : window(win), oldMove(-1, -1) {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            lights[i][j] = false;
        }
    }
    lights[3][4] = true;
    lights[4][3] = true;
    lights[4][4] = true;
    srand(time(NULL));
}


