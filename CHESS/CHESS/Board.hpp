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
#include "Hueristic.hpp"
#pragma once

using namespace std;

void createBoard(map<pair<char, int>, pair<Pieces*, bool>> &init, Hueristic &order);

void editBoard(string color, map<pair<char, int>, pair<Pieces*, bool>> &edited, Hueristic &order);

void printBoard(map<pair<char, int>, pair<Pieces*, bool>> &printing);

void graphicsBoard(map<pair<char, int>, pair<Pieces*, bool>> &graphic, sf::RenderWindow &window);







        
