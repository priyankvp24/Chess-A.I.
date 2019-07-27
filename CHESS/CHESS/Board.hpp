//
//  Board.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/21/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <iterator>
#include <string>
#include "Pieces.hpp"
#pragma once
using namespace std;

int charToInt(const char &x);

void createBoard(map<pair<char, int>, pair<Pieces*, bool>> &init);

void editBoard(string color, map<pair<char, int>, pair<Pieces*, bool>> &edited);

void printBoard(map<pair<char, int>, pair<Pieces*, bool>> &printing);

void graphicsBoard(map<pair<char, int>, pair<Pieces*, bool>> &graphic, sf::RenderWindow &window);





        
