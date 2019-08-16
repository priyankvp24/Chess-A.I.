//
//  BoardTest.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/23/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Game.hpp"

#include <cassert>


int main() {
    
    Hueristic testHueristic;
    map<pair<char, int>, pair<Pieces*, bool>> testB;
    createBoard(testB, testHueristic);
    
    printBoard(testB);
    
    editBoard("A7", testB, testHueristic);
    editBoard("A5", testB, testHueristic);
    editBoard("C7", testB, testHueristic);
    editBoard("D7", testB, testHueristic);
    editBoard("E7", testB, testHueristic);
    editBoard("F7", testB, testHueristic);
    editBoard("G7", testB, testHueristic);
    editBoard("H7", testB, testHueristic);
    
    editBoard("A8" , testB, testHueristic);
    editBoard("C8", testB, testHueristic);
    editBoard("F8", testB, testHueristic);
    
    
    
    
    
    
    
    

}


