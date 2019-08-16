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

int main(int argc, char** argv)
{
    
    Game chess;
    
    if (argc == 2) {
        
        string playerMode = argv[1];
        if (playerMode == "playerVplayer") {
            chess.playGame(playerMode, "N/A");
        }
    }
    
    else if (argc == 3) {
        
        string cpuMode = argv[1];
        string playerColor = argv[2];
        string humanColor = "black";
        string altHumanColor = "white";
        
        if (cpuMode == "playerVcpu" &&
            (playerColor == humanColor || playerColor == altHumanColor)) {
            chess.playGame(cpuMode, playerColor);
        }
        
    }
    
    else {
        return 0;
    }
    
    
}
