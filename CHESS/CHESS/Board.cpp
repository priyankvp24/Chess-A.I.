//
//  Board.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/21/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Board.hpp"

//converts a number that is a char to an actually int my manipulating ASCII code
int charToInt(const char &x) {
    return (x-48);
}

//linear search of a vector seeing if move appears in searching
//returns a true bool if move is in searching, returns false otherwise
bool searchVec(vector<pair<char, int>> &searching, pair<char, int> &move) {

    for (int i = 0; i < searching.size(); ++i) {
        
        if (searching[i] == move) {
            return true;
        }
        
    }
    
    return false;
    
}

//creates the intial state of the board using a map class
void createBoard(map<pair<char, int>, pair<Pieces*, bool>> &init) {
    
    for(int i = 0; i < 8; ++i) {
        
        Pieces* whitePawn = PieceFactory("Pawn", "white", 65 + i, 2, "Wpawn.png");
        pair<char, int> pawnInfo(whitePawn->get_letter(), whitePawn->get_number());
        pair<Pieces*, bool> pawnInfo2(whitePawn, true);
        init[pawnInfo] = pawnInfo2;
        
        Pieces* blackPawn = PieceFactory("Pawn", "black", 65 + i, 7, "Bpawn.png");
        pair<char, int> otherInfo(blackPawn->get_letter(), blackPawn->get_number());
        pair<Pieces*, bool> otherInfo2(blackPawn, true);
        init[otherInfo] = otherInfo2;
        
        if (i == 0 || i == 7) {
            Pieces* whiteRook = PieceFactory("Rook", "white" , 65 + i, 1, "Wrook.png");
            pair<char, int> rookInfo(whiteRook->get_letter(), whiteRook->get_number());
            pair<Pieces*, bool> rookInfo2(whiteRook, true);
            init[rookInfo] = rookInfo2;
            
            Pieces* blackRook = PieceFactory("Rook", "black" , 65 + i, 8, "Brook.png");
            pair<char, int> otherInfo(blackRook->get_letter(), blackRook->get_number());
            pair<Pieces*, bool> otherInfo2(blackRook, true);
            init[otherInfo] = otherInfo2;
        }
        
        if (i == 1 || i == 6) {
            Pieces* whiteKnight = PieceFactory("Knight", "white" , 65 + i, 1, "Wknight.png");
            pair<char, int> knightInfo(whiteKnight->get_letter(), whiteKnight->get_number());
            pair<Pieces*, bool> knightInfo2(whiteKnight, true);
            init[knightInfo] = knightInfo2;
            
            Pieces* blackKnight = PieceFactory("Knight", "black" , 65 + i, 8, "Bknight.png");
            pair<char, int> otherInfo(blackKnight->get_letter(), blackKnight->get_number());
            pair<Pieces*, bool> otherInfo2(blackKnight, true);
            init[otherInfo] = otherInfo2;
            
        }
        
        if (i == 2 || i == 5) {
            Pieces* whiteBishop = PieceFactory("Bishop", "white" , 65 + i, 1, "Wbishop.png");
            pair<char, int> bishopInfo(whiteBishop->get_letter(), whiteBishop->get_number());
            pair<Pieces*, bool> bishopInfo2(whiteBishop, true);
            init[bishopInfo] = bishopInfo2;
            
            Pieces* blackBishop = PieceFactory("Bishop", "black" , 65 + i, 8, "Bbishop.png");
            pair<char, int> otherInfo(blackBishop->get_letter(), blackBishop->get_number());
            pair<Pieces*, bool> otherInfo2(blackBishop, true);
            init[otherInfo] = otherInfo2;
        }
        
        if (i == 4) {
            Pieces* whiteQueen = PieceFactory("Queen", "white", 'E', 1, "Wqueen.png");
            pair<char, int> queenInfo(whiteQueen->get_letter(), whiteQueen->get_number());
            pair<Pieces*, bool> queenInfo2(whiteQueen, true);
            init[queenInfo] = queenInfo2;
            
            Pieces* blackQueen = PieceFactory("Queen", "black", 'E', 8, "Bqueen.png");
            pair<char, int> otherInfo(blackQueen->get_letter(), blackQueen->get_number());
            pair<Pieces*, bool> otherInfo2(blackQueen, true);
            init[otherInfo] = otherInfo2;
        }
            
        if (i == 3) {
            Pieces* whiteKing = PieceFactory("King", "white", 'D', 1, "Wking.png");
            pair<char, int> kingInfo(whiteKing->get_letter(), whiteKing->get_number());
            pair<Pieces*, bool> kingInfo2(whiteKing, true);
            init[kingInfo] = kingInfo2;
            
            Pieces* blackKing = PieceFactory("King", "black", 'D', 8, "Bking.png");
            pair<char, int> otherInfo(blackKing->get_letter(), blackKing->get_number());
            pair<Pieces*, bool> otherInfo2(blackKing, true);
            init[otherInfo] = otherInfo2;
        }
        
        for (int j = 3; j <= 6; ++j) {
            pair<char, int> startEmpty(65 + i, j);
            pair<Pieces*, bool> startEmpty2(nullptr,false);
            init[startEmpty] = startEmpty2;
        }
        
        
    }

}

//uses restrictedMovement function to ask the user what they want to change
//then verifying that their move is valid
void editBoard (string color, map<pair<char, int>, pair<Pieces*, bool>> &edited) {
    
    cout << "Which pieces would you like to move " << color << "?" << endl;
    
    bool validPiece = false;
    string coordinate;
    vector<pair<char, int>> options;
    
    while (!validPiece) {
        
        cin >> coordinate;
        pair<char, int> piece(coordinate[0], charToInt(coordinate[1]));
        
        if (!edited[piece].second) {
            cout << "There is no piece to move at that spot! It is EMPTY" << endl;
        }
        
        else if (edited[piece].second && edited[piece].first->get_color() != color) {
            cout << "That's not a " << color << " piece" << endl;
        }
        
        else {
            options = (edited[piece].first)->
            restrictedMovement((edited[piece].first)->possibleMovement(), edited);
            
            if (options.size() == 0) {
                cout << "That piece can't even move anywhere, picka diffrent one" << endl;
            }
            
            else {
                validPiece = true;
            }
        }
    }
    
    pair<char, int> search(coordinate[0], charToInt(coordinate[1]));
    
    cout << "Select an option:" << endl;
    
    for (vector<pair<char, int>> :: iterator i = options.begin(); i != options.end(); ++i) {
        
        vector<pair<char, int>> :: iterator j(i);
        
        if (++j == options.end()) {
            cout << (*i).first << (*i).second << endl;
        }
        else {
            cout << (*i).first << (*i).second << ", ";
        }
        
    }
   
    string wantedMovement;
    bool validMove = false;
    
    while (!validMove) {
        
        cout << endl;
        cin >> wantedMovement;
        
        pair<char, int> move(wantedMovement[0], charToInt(wantedMovement[1]));
        pair<char, int> search(coordinate[0], charToInt(coordinate[1]));
        
        if (wantedMovement[0] < 'A' || wantedMovement[0] > 'H' ||
            charToInt(wantedMovement[1]) < 1 || charToInt(wantedMovement[1]) > 8 ) {
            cout << "You can't move off an 8 x 8 board!" << endl;
        }
        
        else if (!searchVec(options, move)) {
            cout << "You can't move there!" << endl;
            
            if (edited[move].first->get_color() == edited[search].first->get_color()) {
                cout << "Friendly fire, you can't do that!" << endl;
            }
        }
        
        else if (edited[move].second == false) {
            
            edited[move].first = edited[search].first;
            edited[move].first->set_letter(move.first);
            edited[move].first->set_number(move.second);
            edited[move].second = true;
            
            edited[search].first = nullptr;
            edited[search].second = false;
            
            validMove = true;
            
        }
        
        else {
            
            delete edited[move].first;
            edited[move].first = edited[search].first;
            edited[move].first->set_letter(move.first);
            edited[move].first->set_number(move.second);
            
            edited[search].first = nullptr;
            edited[search].second = false;
            
            validMove = true;
        }
    }
    
    pair<char, int> move(wantedMovement[0], charToInt(wantedMovement[1]));
    edited[move].first->update_sprite(xCoordinates(move.first), yCoordinates(move.second));
    
}

//prints the board to the standard output
void printBoard(map<pair<char, int>, pair<Pieces*, bool>> &printing) {
    
    map<pair<char, int>, pair<Pieces*, bool>> :: iterator traverse;
    
    for (traverse = printing.begin(); traverse != printing.end(); ++traverse) {
        cout << ((*traverse).first).first << ((*traverse).first).second;
        
        if ((((*traverse).second).first) != nullptr) {
            
            cout << " " << (((*traverse).second).first)->get_name() << " " <<
            (((*traverse).second).first)->get_color() << endl;
            
        }
        
        else {cout << endl;}
        
    }
}

//prints all the sprites associated with pieces that exist on boards
void graphicsBoard(map<pair<char, int>, pair<Pieces*, bool>> &graphic, sf::RenderWindow &window) {
    
    map<pair<char, int>, pair<Pieces*, bool>> :: iterator i;
    
    for (i = graphic.begin(); i != graphic.end(); ++i) {
        
        if (((*i).second).second) {
            window.draw((((*i).second).first)->get_sprite());
        }
        
    }

}




            


