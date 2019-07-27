//
//  BoardTest.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/23/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Board.hpp"

#include <cassert>


int main() {
    
    map<pair<char, int>, pair<Pieces*, bool>> testB;
    createBoard(testB);
    
    printBoard(testB);
    
    editBoard("A7", testB);
    editBoard("A5", testB);
    editBoard("C7", testB);
    editBoard("D7", testB);
    editBoard("E7", testB);
    editBoard("F7", testB);
    editBoard("G7", testB);
    editBoard("H7", testB);
    
    editBoard("A8" , testB);
    editBoard("C8", testB);
    editBoard("F8", testB);
    
    
    
    
    
    
    
    

}


