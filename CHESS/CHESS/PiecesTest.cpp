//
//  PiecesTest.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/13/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Pieces.hpp"
#include <cassert>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    Pieces* queen1 = PieceFactory("Queen", "white", 'B', 5, "Bqueen.png");
    vector<pair <char, int>> testing6 = queen1->possibleMovement();
    for (int i = 0; i < testing6.size(); ++i) {
        cout << testing6[i].first << testing6[i].second << endl;
    }
    
    delete queen1;
    
    cout << endl;
    
    Pieces* pawn1 = PieceFactory("Pawn", "white", 'B', 5, "Bpawn.png");
    vector<pair <char, int>> testing = pawn1->possibleMovement();
    for (int i = 0; i < testing.size(); ++i) {
        cout << testing[i].first << testing[i].second << endl;
    }
    
    //create a destructor that is virtual
    delete pawn1;
    
    cout << endl;
    
    Pieces* rook1 = PieceFactory("Rook", "white", 'A', 1, "Brook.png");
    vector<pair <char, int>> testing2 = rook1->possibleMovement();
    for (int i = 0; i < testing2.size(); ++i) {
        cout << testing2[i].first << testing2[i].second << endl;
    }
    
    delete rook1;
    
    cout << endl;
    
    Pieces* bishop1 = PieceFactory("Bishop", "white", 'D', 5, "Bbishop.png");
    vector<pair <char, int>> testing3 = bishop1->possibleMovement();
    for (int i = 0; i < testing3.size(); ++i) {
        cout << testing3[i].first << testing3[i].second << endl;
    }
    
    delete bishop1;
    
    cout << endl;
    
    Pieces* knight1 = PieceFactory("Knight", "white", 'B', 5, "Bknight.png");
    vector<pair <char, int>> testing4 = knight1->possibleMovement();
    for (int i = 0; i < testing4.size(); ++i) {
        cout << testing4[i].first << testing4[i].second << endl;
    }
    
    delete knight1;
    
    cout << endl;
    
    Pieces* knight2 = PieceFactory("Knight", "white", 'D', 5, "Bknight.png");
    vector<pair <char, int>> testing5 = knight2->possibleMovement();
    for (int i = 0; i < testing5.size(); ++i) {
        cout << testing5[i].first << testing5[i].second << endl;
    }
    
    delete knight2;
    
    cout << endl;
    
    Pieces* king1 = PieceFactory("King", "white", 'B', 5, "Bking.png");
    vector<pair<char, int>> testing7 = king1->possibleMovement();
    for (int i = 0; i < testing7.size(); ++i) {
        cout << testing7[i].first << testing7[i].second << endl;
    }
    
    delete king1;
    
    
}


