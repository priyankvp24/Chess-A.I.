//
//  HueristicTest.cpp
//  CHESS
//
//  Created by Priyank Patel on 8/9/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include <stdio.h>
#include "Game.hpp"
#include <cassert>

//converts a number that is a char to an int by manipulating ASCII code
int charToInt3(const char &c) {
    return (c-48);
}

//converts a number that is a int to a char by manipulating ASCII code
char intToChar3(const int &i) {
    return (i + 48);
}



int main() {
    
    Hueristic h;
    map<pair<char, int>, pair<Pieces*, bool>> m;
    createBoard(m, h);
    
    for (int i = 0; i < (h.getPiecesList("white")).size(); ++i) {
        cout << h.getPiecesList("white")[i]->get_color() << ", " << h.getPiecesList("white")[i]->get_name() << endl;
    }
    
    for (int i = 0; i < (h.getPiecesList("black")).size(); ++i) {
        cout << h.getPiecesList("black")[i]->get_color() << ", " << h.getPiecesList("black")[i]->get_name() << endl;
    }
    
    
    /**editBoard ("white", m, h);
     editBoard ("black", m, h);
     
     editBoard ("white", m, h);
     editBoard ("black", m, h);**/
    
    for (int i = 0; i < (h.getPiecesList("white")).size(); ++i) {
        
        if (h.getPiecesList("white")[i] != nullptr) {
            cout << h.getPiecesList("white")[i]->get_color() << ", " << h.getPiecesList("white")[i]->get_name() << endl;
        }
        
    }
    
    for (int i = 0; i < (h.getPiecesList("black")).size(); ++i) {
        
        if (h.getPiecesList("black")[i] != nullptr) {
            cout << h.getPiecesList("black")[i]->get_color() << ", " << h.getPiecesList("black")[i]->get_name() << endl;
        }
        
    }
    
    cout << endl << endl << endl;
    
    
    cout << "*************************************************" << endl;
    
    pair<char, int> init('E', 1);
    pair<char, int> move('E', 5);
    h.executeMove(init, move, m);
    vector<pair<string, string>> possMoves = h.getLegalMoves("white", m);
    vector<pair<string, string>> :: const_iterator i;
    for(i = possMoves.begin(); i != possMoves.end(); ++i) {
        cout << (*i).first[0] << charToInt3((*i).first[1]) << " :: " <<
        (*i).second[0] << charToInt3((*i).second[1]) << endl;
    }
    
    pair<char, int> initBlackQ('E', 8);
    pair<char, int> moveBlackQ('E', 3);
    h.executeMove(initBlackQ, moveBlackQ, m);
    
    Hueristic cloneH;
    map<pair<char, int>, pair<Pieces*, bool>> cloneB = cloneH.cloneBoard(m, cloneH);
    
    cout << "************************THE ORIGINAL*************************" << endl;
    
    vector<pair<string, string>> possMoves2 = h.getLegalMoves("white", m);
    vector<pair<string, string>> :: const_iterator k;
    for(k = possMoves2.begin(); k != possMoves2.end(); ++k) {
        cout << (*k).first[0] << charToInt3((*k).first[1]) << " :: " <<
        (*k).second[0] << charToInt3((*k).second[1]) << endl;
    }
    
    cout << "************************THE CLONE*************************" << endl;

    vector<pair<string, string>> possMoves3 = cloneH.getLegalMoves("white", cloneB);
    vector<pair<string, string>> :: const_iterator j;
    for(j = possMoves3.begin(); j != possMoves3.end(); ++j) {
        cout << (*j).first[0] << charToInt3((*j).first[1]) << " :: " <<
        (*j).second[0] << charToInt3((*j).second[1]) << endl;
    }
    
    cout << "************************THE EVALUATION*************************" << endl;
    
    Hueristic evalH;
    map<pair<char, int>, pair<Pieces*, bool>> evalM;
    createBoard(evalM, evalH);
    
    cout << evalH.evaluateBoard(evalM) << endl;
    
    cout << h.evaluateBoard(m) << endl;
    
    
    
    
    
    
    

    
    
    
}
