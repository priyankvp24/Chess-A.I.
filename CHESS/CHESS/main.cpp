//
//  main.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/8/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    
    Game chess;
    
    // insert code here...
    sf::RenderWindow window(sf::VideoMode(2560, 1920), "CHESS");
    map<pair<char, int>, pair<Pieces*, bool>> initialBoard;
    createBoard(initialBoard);
    
    int turnTracker = 0;
    
    while (window.isOpen())
    {
    
        
        //if turnTracker is even, ask white
        if (turnTracker % 2 == 0 && turnTracker != 0) {
            
            editBoard("white", initialBoard);
            
        }
        
        if (turnTracker % 2 != 0) {
            
            editBoard("black", initialBoard);
            
        }
        
        ++turnTracker;
        
        sf::Event event;
        
        //handles events
        while (window.pollEvent(event))
        {
            
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    
                
            }
        }
        
        //update the game
        window.clear();
        
        //draw objects here
        
        //*****wooden desk texture/creation using sprites*****
        chess.setUpBoard(window);
        
        graphicsBoard(initialBoard, window);
        
        if (turnTracker % 2 != 0) {
            chess.isKingDead(window, initialBoard, "black", "white");
        }
        
        if (turnTracker % 2 == 0) {
            chess.isKingDead(window, initialBoard, "white", "black");
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
    
        
        window.display();
        
    }
}
