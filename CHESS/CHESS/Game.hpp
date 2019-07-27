//
//  Game.hpp
//  CHESS
//
//  Created by Priyank Patel on 7/17/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.hpp"

#endif /* Game_hpp */


class Game {
    
public:
    
    void playGame();
    void setUpBoard(sf::RenderWindow &window);
    void isKingDead(sf::RenderWindow &window, const map<pair<char, int>, pair<Pieces*, bool>> &board, string checkColor, string otherColor);
    
private:
    
};
