//
//  Hueristic.cpp
//  CHESS
//
//  Created by Priyank Patel on 8/3/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Hueristic.hpp"
#include <limits>

vector<pair<char, int>> traverseOrder() {
    
    vector<pair<char, int>> mapOrder;
    for (int column = 65; column < 73; ++column) {
        for (int row = 1; row < 9; ++row) {
            pair<char, int> addition(column, row);
            mapOrder.push_back(addition);
        }
    }
    
    return mapOrder;
}

const vector<pair<char, int>> order(traverseOrder());

//converts a number that is a char to an int by manipulating ASCII code
int charToInt1(const char &c) {
    return (c-48);
}

//converts a number that is a int to a char by manipulating ASCII code
char intToChar1(const int &i) {
    return (i + 48);
}

pair<char, int> stringToPair (string coordinates) {
    
    pair<char, int> pair(coordinates[0], charToInt1(coordinates[1]));
    return pair;
    
}

string pairToString (pair<char, int> coords) {
    
    string stringCoords;
    
    stringCoords = coords.first;
    stringCoords += intToChar1(coords.second);
    
    return stringCoords;
}

bool diagonalThreat (map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord) {
    
    bool diagThreat = false;
    
    Pieces* safeCheckPiece = board[coord].first;
    
    //on the first diagonal
    pair<char, int> goingUp(safeCheckPiece->get_letter() + 1, safeCheckPiece->get_number() - 1);
    pair<char, int> goingDown(safeCheckPiece->get_letter() - 1, safeCheckPiece->get_number() + 1);
    
    //on the second diagonal
    pair<char, int> goingUp2(safeCheckPiece->get_letter() - 1, safeCheckPiece->get_number() - 1);
    pair<char, int> goingDown2(safeCheckPiece->get_letter() + 1, safeCheckPiece->get_number() + 1);
    
    while((goingUp.first <= 'H' && goingUp.second >= 1) && !board[goingUp].second) {
        goingUp.first++;
        goingUp.second--;
    }
    
    if ((goingUp.first <= 'H' && goingUp.second >= 1) &&
        (board[goingUp].first->get_color() != safeCheckPiece->get_color()) &&
        (board[goingUp].first->get_name() == "Bishop" || board[goingUp].first->get_name() == "Queen")) {return true;}
    
    else if ((goingUp.first <= 'H' && goingUp.second >= 1) &&
             (board[goingUp].first->get_color() != safeCheckPiece->get_color()) &&
             board[goingUp].first->get_name() == "King" &&
             (goingUp.first == safeCheckPiece->get_letter() + 1 &&
              goingUp.second == safeCheckPiece->get_number() - 1)) {return true;}
    
    while((goingDown.first >= 'A' && goingDown.second <= 8) && !board[goingDown].second) {
        goingDown.first--;
        goingDown.second++;
    }
    
    if ((goingDown.first >= 'A' && goingDown.second <= 8) &&
        (board[goingDown].first->get_color() != safeCheckPiece->get_color()) &&
        (board[goingDown].first->get_name() == "Bishop" || board[goingDown].first->get_name() == "Queen")) {return true;}
    
    else if ((goingDown.first >= 'A' && goingDown.second <= 8) &&
             (board[goingDown].first->get_color() != safeCheckPiece->get_color()) &&
             board[goingDown].first->get_name() == "King" &&
             (goingDown.first == safeCheckPiece->get_letter() - 1 &&
              goingDown.second == safeCheckPiece->get_number() + 1)) {return true;}
    
    while((goingUp2.first >= 'A' && goingUp2.second >= 1) && !board[goingUp2].second) {
        goingUp2.first--;
        goingUp2.second--;
    }
    
    if ((goingUp2.first >= 'A' && goingUp2.second >= 1) &&
        (board[goingUp2].first->get_color() != safeCheckPiece->get_color()) &&
        (board[goingUp2].first->get_name() == "Bishop" || board[goingUp2].first->get_name() == "Queen")) {return true;}
    
    else if ((goingUp2.first >= 'A' && goingUp2.second >= 1) &&
             (board[goingUp2].first->get_color() != safeCheckPiece->get_color()) &&
             board[goingUp2].first->get_name() == "King" &&
             (goingUp2.first == safeCheckPiece->get_letter() - 1 &&
              goingUp2.second == safeCheckPiece->get_number() - 1)) {return true;}
    
    while((goingDown2.first <= 'H' && goingDown2.second <= 8) && !board[goingDown2].second) {
        goingDown2.first++;
        goingDown2.second++;
    }
    
    if ((goingDown2.first <= 'H' && goingDown2.second <= 8) &&
        (board[goingDown2].first->get_color() != safeCheckPiece->get_color()) &&
        (board[goingDown2].first->get_name() == "Bishop" || board[goingDown2].first->get_name() == "Queen")) {return true;}
    
    else if ((goingDown2.first <= 'H' && goingDown2.second <= 8) &&
             (board[goingDown2].first->get_color() != safeCheckPiece->get_color()) &&
             board[goingDown2].first->get_name() == "King" &&
             (goingDown2.first == safeCheckPiece->get_letter() + 1 &&
              goingDown2.second == safeCheckPiece->get_number() + 1)) {return true;}
    
    return diagThreat;
    
}

bool perpendicularThreat (map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord) {
    
    bool perpThreat = false;
    
    Pieces* safeCheckPiece = board[coord].first;
    
    int goingUp = safeCheckPiece->get_number() - 1;
    pair<char, int> option1(safeCheckPiece->get_letter(), goingUp);
    while((goingUp >= 1) && !board[option1].second) {
        option1.first = safeCheckPiece->get_letter();
        option1.second = goingUp;
        --goingUp;
    }
    
    if ((goingUp >= 1) &&
        (board[option1].first->get_color() != safeCheckPiece->get_color()) &&
        (board[option1].first->get_name() == "Rook" ||
         board[option1].first->get_name() == "Queen")) {return true;}
    
    else if ((goingUp >= 1) &&
             (board[option1].first->get_color() != safeCheckPiece->get_color()) &&
             (option1.second == safeCheckPiece->get_number() - 1) &&
             board[option1].first->get_name() == "King") {return true;}
    
    /****************************************************************************************************************/
    
    char goingRight = safeCheckPiece->get_letter() + 1;
    pair<char, int> option3(goingRight, safeCheckPiece->get_number());
    while(goingRight != 'I'  && !board[option3].second) {
        option3.first = goingRight;
        option3.second = safeCheckPiece->get_number();
        ++goingRight;
    }
    
    if ((goingRight != 'I') &&
        (board[option3].first->get_color() != safeCheckPiece->get_color()) &&
        (board[option3].first->get_name() == "Rook" ||
         board[option3].first->get_name() == "Queen")) {return true;}
    
    else if ((goingRight != 'I') &&
             (board[option3].first->get_color() != safeCheckPiece->get_color()) &&
             (option3.first == safeCheckPiece->get_letter() + 1) &&
             board[option3].first->get_name() == "King") {return true;}
    
    /****************************************************************************************************************/
    
    int goingDown = safeCheckPiece->get_number() + 1;
    pair<char, int> option2(safeCheckPiece->get_letter(),goingDown);
    while(goingDown < 9 && !board[option2].second) {
        option2.first = safeCheckPiece->get_letter();
        option2.second = goingDown;
        ++goingDown;
    }
    
    if ((goingDown < 9) &&
        (board[option2].first->get_color() != safeCheckPiece->get_color()) &&
        (board[option2].first->get_name() == "Rook" ||
         board[option2].first->get_name() == "Queen")) {return true;}
    
    else if ((goingDown < 9) &&
             (board[option2].first->get_color() != safeCheckPiece->get_color()) &&
             board[option2].first->get_name() == "King" &&
             option2.first == safeCheckPiece->get_number() + 1) {return true;}
    
    /****************************************************************************************************************/
    
    char goingLeft = safeCheckPiece->get_letter() - 1;
    pair<char, int> option4(goingLeft, safeCheckPiece->get_number());
    while(goingLeft != '@' && !board[option4].second) {
        option4.first = goingLeft;
        option4.second = safeCheckPiece->get_number();
        --goingLeft;
    }
    
    if ((goingLeft != '@') &&
        (board[option4].first->get_color() != safeCheckPiece->get_color()) &&
        (board[option4].first->get_name() == "Rook" || board[option4].first->get_name() == "Queen")) {return true;}
    
    else if ((goingLeft != '@') &&
             (board[option4].first->get_color() != safeCheckPiece->get_color()) &&
             board[option4].first->get_name() == "King"
             && option4.first == safeCheckPiece->get_letter() - 1) {return true;}
    
    /****************************************************************************************************************/
    
    return perpThreat;
}

bool knightThreat (map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord) {
    
    vector<pair<char, int>> possibilities;
    char letter = coord.first;
    int num =  coord.second;
    
    //upRight
    if (letter != 'H' && num > 2) {
        pair<char, int> upRight(letter + 1, num - 2);
        possibilities.push_back(upRight);
    }
    
    //upLeft
    if (letter != 'A' && num > 2) {
        pair<char, int> upLeft(letter - 1, num - 2);
        possibilities.push_back(upLeft);
    }
    
    //leftUp
    if (letter > 66 && num > 1) {
        pair<char, int> leftUp(letter - 2, num - 1);
        possibilities.push_back(leftUp);
    }
    
    //leftDown
    if (letter > 66 && num < 8) {
        pair<char, int> leftDown(letter - 2, num + 1);
        possibilities.push_back(leftDown);
    }
    
    //rightUp
    if (letter < 71 && num > 1) {
        pair<char, int> rightUp(letter + 2, num - 1);
        possibilities.push_back(rightUp);
    }
    
    //rightDown
    if (letter < 71 && num < 8) {
        pair<char, int> rightDown(letter + 2, num + 1);
        possibilities.push_back(rightDown);
    }
    
    //downRight
    if (letter != 'H' && num < 7) {
        pair<char, int> downRight(letter + 1, num + 2);
        possibilities.push_back(downRight);
    }
    
    //downLeft
    if (letter != 'A' && num < 7) {
        pair<char, int> downLeft(letter - 1, num + 2);
        possibilities.push_back(downLeft);
    }
    
    for (size_t i = 0; i < possibilities.size(); ++i) {
        
        if ((board[possibilities[i]].second) &&
            (board[possibilities[i]].first->get_name() == "Knight") &&
            board[possibilities[i]].first->get_color() != board[coord].first->get_color())
        {return true;}
    }
    
    return false;
    
}

bool pawnThreat (map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord) {
    
    string pieceColor = board[coord].first->get_color();
    
    pair<char, int> pawnAttack(coord.first, coord.second);
    pair<char, int> pawnAttackAlt(coord.first, coord.second);
    
    if (pieceColor == "white") {
        if (coord.first == 'A') {
            pawnAttack.first++;
            pawnAttack.second++;
        }
        
        else if (coord.first == 'H') {
            pawnAttack.first--;
            pawnAttack.second++;
        }
        
        else {
            pawnAttack.first++;
            pawnAttack.second++;
            pawnAttackAlt.first--;
            pawnAttackAlt.second++;
        }
    }
    
    else {
        if (coord.first == 'A') {
            pawnAttack.first++;
            pawnAttack.second--;
        }
        
        else if (coord.first == 'H') {
            pawnAttack.first--;
            pawnAttack.second--;
        }
        
        else {
            pawnAttack.first++;
            pawnAttack.second--;
            pawnAttackAlt.first--;
            pawnAttackAlt.second--;
            
        }
    }
    
    if ((board[pawnAttack].second) &&
        board[pawnAttack].first->get_color() != board[coord].first->get_color() &&
        board[pawnAttack].first->get_name() == "Pawn") {return true;}
    
    else if ((board[pawnAttackAlt].second) &&
             board[pawnAttackAlt].first->get_color() != board[coord].first->get_color() &&
             board[pawnAttackAlt].first->get_name() == "Pawn") {return true;}
    
    return false;
    
}












Hueristic :: Hueristic(string color): CPUcolor(color) {}

Hueristic :: Hueristic() {}

string Hueristic :: get_CPUcolor() {
    return CPUcolor;
}

void Hueristic :: set_CPUcolor(string color_in) {
    CPUcolor = color_in;
}

void Hueristic :: countPieces (const map<pair<char, int>, pair<Pieces*, bool>> &board) {
    
    map<pair<char, int>, pair<Pieces*, bool>> :: const_iterator i;
    
    for (i = board.begin(); i != board.end(); ++i) {
        
        if (((*i).second).first == nullptr) {}
        
        else if ((((*i).second).first)->get_color() == "white") {
            whitePieces.push_back((((*i).second).first));
        }
        
        else if ((((*i).second).first)->get_color() == "black") {
            whitePieces.push_back((((*i).second).first));
        }
        
    }
    
}

void Hueristic :: addPiece (string color, Pieces* &addition, Hueristic &H) {
    
    if (color == "white") {
        H.getPiecesList("white").push_back(addition);
    }
    
    if (color == "black") {
         H.getPiecesList("black").push_back(addition);
    }
    
}

void Hueristic :: removePiece (string color, Pieces* &remove, Hueristic &H) {
    
    if (remove == nullptr) {
        exception e;
        throw e;
    }
    
    if (color == "white") {
        int i = 0;
        
        while (H.getPiecesList("white")[i] != remove) {
            ++i;
        }
        
        H.getPiecesList("white")[i] = nullptr;
    }
    
    if (color == "black") {
        int i = 0;
        
        while (H.getPiecesList("black")[i] != remove) {
            ++i;
        }
        
        H.getPiecesList("black")[i] = nullptr;
    }
    
}

int Hueristic :: findPiece(string pieceColor, Pieces* location, Hueristic &H) {
    
    if (pieceColor == "white") {
        
        char originalLet = location->get_letter();
        int originalNum = location->get_number();
        
        int i = 0;
        
        while ((H.getPiecesList("white")[i]->get_letter() != originalLet || H.getPiecesList("white")[i]->get_number() != originalNum) && i < 15) {
            ++i;
            
            while (H.getPiecesList("white")[i] == nullptr) {++i;}
        }
        
        return i;
        
    }
    
    else {
        
        char originalLet = location->get_letter();
        int originalNum = location->get_number();
        
        int i = 0;
        
        while ((H.getPiecesList("black")[i]->get_letter() != originalLet || H.getPiecesList("black")[i]->get_number() != originalNum) && i < 15) {
            ++i;
            
            while (H.getPiecesList("black")[i] == nullptr) {++i;}
        }
        
        return i;
        
    }
}

vector<Pieces*>& Hueristic :: getPiecesList (string color) {
    
    if (color == "white") {
        return whitePieces;
    }
    
    else if (color == "black") {
        return blackPieces;
    }
    
    else {
        exception e;
        throw e;
    }
    
}

vector<pair<string, string>> Hueristic :: getLegalMoves (string color, map<pair<char, int>, pair<Pieces*, bool>> &board, Hueristic &H) {
    
    vector<pair<string, string>> legalMoves;

    
    if (color == "white") {
        
        for (size_t i = 0; i < H.getPiecesList("white").size(); ++i) {
            if (H.getPiecesList("white")[i] != nullptr) {
                
                vector<pair<char, int>> possMoves = H.getPiecesList("white")[i]->possibleMovement();
                vector<pair<char, int>> movesForAPiece = H.getPiecesList("white")[i]->restrictedMovement(possMoves, board);
                for (size_t j = 0; j < movesForAPiece.size(); ++j) {
                    pair<char, int> current(H.getPiecesList("white")[i]->get_letter(), H.getPiecesList("white")[i]->get_number());
                    string currentS = pairToString(current);
                    string moveS = pairToString(movesForAPiece[j]);
                    pair<string, string> addition(currentS, moveS);
                    legalMoves.push_back(addition);
                }
        
            }
        }
        
    }
    
    else {
        
        for (size_t i = 0; i < H.getPiecesList("black").size(); ++i) {
            
            if (H.getPiecesList("black")[i] != nullptr) {
                
                vector<pair<char, int>> possMoves = H.getPiecesList("black")[i]->possibleMovement();
                vector<pair<char, int>> movesForAPiece = H.getPiecesList("black")[i]->restrictedMovement(possMoves, board);
                for (size_t j = 0; j < movesForAPiece.size(); ++j) {
                    pair<char, int> current(H.getPiecesList("black")[i]->get_letter(), H.getPiecesList("black")[i]->get_number());
                    string currentS = pairToString(current);
                    string moveS = pairToString(movesForAPiece[j]);
                    pair<string, string> addition(currentS, moveS);
                    legalMoves.push_back(addition);
                }
                
            }
    
        }
        
    }
    
    return legalMoves;
}

void Hueristic :: executeMove (pair<char, int> current, pair<char, int> wantedMove, map<pair<char, int> , pair<Pieces*, bool>> &board, Hueristic &H) {
    
    if (board[wantedMove].second == false) {
        
        int indexOfPiece = findPiece(board[current].first->get_color(), board[current].first, H);
        
        if (board[current].first->get_color() == "white") {
            H.getPiecesList("white")[indexOfPiece]->set_letter(wantedMove.first);
            H.getPiecesList("white")[indexOfPiece]->set_number(wantedMove.second);
        }
        else if (board[current].first->get_color() == "black") {
            H.getPiecesList("black")[indexOfPiece]->set_letter(wantedMove.first);
            H.getPiecesList("black")[indexOfPiece]->set_number(wantedMove.second);
        }
        
        board[wantedMove].first = board[current].first;
        board[wantedMove].first->set_letter(wantedMove.first);
        board[wantedMove].first->set_number(wantedMove.second);
        board[wantedMove].second = true;
        
        board[current].first = nullptr;
        board[current].second = false;
        
        
        
    }
    else {
        
        if (board[current].first->get_color() != board[wantedMove].first->get_color()) {
            
            
            int indexOfPiece = findPiece(board[current].first->get_color(), board[current].first, H);
            
            if (board[current].first->get_color() == "white") {
                H.getPiecesList("white")[indexOfPiece]->set_letter(wantedMove.first);
                H.getPiecesList("white")[indexOfPiece]->set_number(wantedMove.second);
            }
            else if (board[current].first->get_color() == "black") {
                H.getPiecesList("black")[indexOfPiece]->set_letter(wantedMove.first);
                H.getPiecesList("black")[indexOfPiece]->set_number(wantedMove.second);
            }
            
            (*this).removePiece(board[wantedMove].first->get_color(), board[wantedMove].first, H);
            delete board[wantedMove].first;
            board[wantedMove].first = board[current].first;
            board[wantedMove].first->set_letter(wantedMove.first);
            board[wantedMove].first->set_number(wantedMove.second);
            
            board[current].first = nullptr;
            board[current].second = false;
            
        }
  
    }
    
    board[wantedMove].first->update_sprite(xCoordinates(wantedMove.first), yCoordinates(wantedMove.second));
    
}

map<pair<char, int>, pair<Pieces*, bool>> Hueristic :: cloneBoard(map<pair<char, int>, pair<Pieces*, bool>> &board, Hueristic &cloneH) {
    
    map<pair<char, int>, pair<Pieces*, bool>> clone;
    vector<pair<char, int>> :: const_iterator i;
    
    for (i = order.begin(); i != order.end(); ++i) {
        
        if(board[*i].first) {
            Pieces* cloneP = PieceFactory(board[*i].first->get_name(),
                        board[*i].first->get_color(), board[*i].first->get_letter(),
                        board[*i].first->get_number(), board[*i].first->get_filename());
            
            if (board[*i].first->get_color() == "white") {
                cloneH.addPiece("white", cloneP, cloneH);
            }
            
            else {
                cloneH.addPiece("black", cloneP, cloneH);
            }
            
            pair<Pieces*, bool> cloneVal(cloneP, true);
            clone[*i] = cloneVal;
        }
        
        else {
            pair<Pieces*, bool> cloneVal(nullptr, false);
            clone[*i] = cloneVal;
        }
        
    }

    return clone;
}

void Hueristic :: destructBoard (map<pair<char, int>, pair<Pieces*, bool>> &board) {
    
    map<pair<char, int>, pair<Pieces*, bool>> :: iterator i;
    for (i = board.begin(); i != board.end(); ++i) {
        
        if ((*i).second.first != nullptr && ((*i).first.first != 'E' || (*i).first.second != 1) && ((*i).first.first != 'E' || (*i).first.second != 8)) {
            delete (*i).second.first;
        }
        
    }
    
 
}

bool Hueristic :: isPieceSafe(map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord) {
    
    bool isSafe = true;
    
    if (coord.first < 'A' || coord.first > 'H' || coord.second < 1 || coord.second > 8) {
        exception e;
        throw e;
    }
    
    else if (!board[coord].second) {
        exception e;
        throw e;
    }
    
    else if(pawnThreat(board, coord) || knightThreat(board, coord)
            || perpendicularThreat(board, coord) || diagonalThreat(board, coord))
    {isSafe = false;}
    
    return isSafe;
    
}

bool Hueristic :: kingInCheck(map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &Kcoord) {
    
    if (board[Kcoord].first->get_name() != "King") {
        exception e;
        throw e;
    }
    
    return isPieceSafe(board, Kcoord);
    
    
}

double Hueristic :: piecePositionReEval(Pieces* piece) {
    return piece->findPositionReEval();
}


double Hueristic :: evaluateBoard(map<pair<char, int>, pair<Pieces*, bool>> &board) {
    
    //black high, white low
    double count = 0;
    
    int pawnValue = 10;
    int bishopValue = 30;
    int knightValue = 30;
    int rookValue = 50;
    int queenValue = 90;
    int kingValue = 900;
    double safetyRatio = 3.0;
    
    vector<pair<char, int>> :: const_iterator i;
    for(i = order.begin(); i != order.end(); ++i) {
        
        if (board[*i].first) {
            
            if(board[*i].first->get_color() == "white") {
                
                if (board[*i].first->get_name() == "Pawn") {
                    count -= (pawnValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (pawnValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Rook") {
                    count -= (rookValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (rookValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Knight") {
                    count -= (knightValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (knightValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Bishop") {
                    count -= (bishopValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (bishopValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Queen") {
                    count -= (queenValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (queenValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "King") {
                    count -= (kingValue - piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count -= (kingValue / safetyRatio);
                    }
                }
                
            }
            
            else {
                
                if (board[*i].first->get_name() == "Pawn") {
                    count += (pawnValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (pawnValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Rook") {
                    count += (rookValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (rookValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Knight") {
                    count += (knightValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (knightValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Bishop") {
                    count += (bishopValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (bishopValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "Queen") {
                    count += (queenValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (queenValue / safetyRatio);
                    }
                }
                
                if (board[*i].first->get_name() == "King") {
                    count += (kingValue + piecePositionReEval(board[*i].first));
                    if (isPieceSafe(board, (*i))) {
                        count += (kingValue / safetyRatio);
                    }
                }
                
            }
            
        }
        
    }
    
    return count;
    
}

int Hueristic :: Min (map<pair<char, int>, pair<Pieces*, bool>> &board, int depth, int initialHeight, int beta, int alpha, Hueristic &H) {
    
    if (depth == 0) {
        return evaluateBoard(board);
    }
    
    int minVal = std::numeric_limits<int>::max();
    beta = std::numeric_limits<int>::max();
    alpha = std::numeric_limits<int>::min();
    vector<pair<string, string>> whiteMoves = getLegalMoves("white", board, H);
    vector<pair<string, string>> :: iterator i;
    pair<char, int> optStart;
    pair<char, int> optMove;
    for (i = whiteMoves.begin(); i != whiteMoves.end(); ++i) {
        Hueristic cloneH;
        
        map<pair<char, int>, pair<Pieces*, bool>> clone = cloneBoard(board, cloneH);
        
    
        executeMove(stringToPair((*i).first), stringToPair((*i).second), clone, cloneH);
        int currentVal = Max (clone, depth - 1, initialHeight, beta, alpha, cloneH);
        if (currentVal < minVal) {
            minVal = currentVal;
            optStart = stringToPair((*i).first);
            optMove = stringToPair((*i).second);
        }
        
        if (currentVal <= alpha) {
            
            return minVal;
            
        }
        if (currentVal < beta) {beta = currentVal;}
        
        destructBoard(clone);
    }
    
    if (depth == initialHeight) {
        executeMove(optStart, optMove, board, (*this));
    }
    
    
    return minVal;
    
}

int Hueristic :: Max(map<pair<char, int>, pair<Pieces*, bool>> &board, int depth, int initialHeight, int beta, int alpha, Hueristic &H) {
    
    if (depth == 0) {
        return evaluateBoard(board);
    }
    
    int maxVal = std::numeric_limits<int>::min();
    beta = std::numeric_limits<int>::max();
    alpha = std::numeric_limits<int>::min();
    vector<pair<string, string>> blackMoves = getLegalMoves("black", board, H);
    vector<pair<string, string>> :: iterator i;
    pair<char, int> optStart;
    pair<char, int> optMove;
    for (i = blackMoves.begin(); i != blackMoves.end(); ++i) {
        Hueristic cloneH;

        map<pair<char, int>, pair<Pieces*, bool>> clone = cloneBoard(board, cloneH);
        
        
        executeMove(stringToPair((*i).first), stringToPair((*i).second), clone, cloneH);
        int currentVal = Min(clone, depth - 1, initialHeight, beta, alpha, cloneH);
        if (currentVal > maxVal) {
            maxVal = currentVal;
            optStart = stringToPair((*i).first);
            optMove = stringToPair((*i).second);
        }
        
        if (currentVal >= beta) {
            return maxVal;
            
        }
        if (currentVal > alpha) {alpha = currentVal;}
        
        destructBoard(clone);
    }
    
    if (depth == initialHeight) {
        executeMove(optStart, optMove, board, (*this));
    } 
    
    return maxVal;
}
