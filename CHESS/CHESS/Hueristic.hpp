//
//  Hueristic.hpp
//  CHESS
//
//  Created by Priyank Patel on 8/3/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#ifndef Hueristic_hpp
#define Hueristic_hpp

#include <stdio.h>
#include "Pieces_header.hpp"
#pragma once

#endif /* Hueristic_hpp */

class Hueristic {
    public:
    
        Hueristic(string color);
    
        Hueristic();
    
        string get_CPUcolor();
        void set_CPUcolor(string color_in);
    
        void countPieces(const map<pair<char, int>, pair<Pieces*, bool>> &board);
        vector<Pieces*>& getPiecesList (string color);
        void addPiece(string color, Pieces* &addition, Hueristic &H);
        void removePiece(string color, Pieces* &deletion, Hueristic &H);
        int findPiece(string pieceColor, Pieces* location, Hueristic &H);
        vector<pair<string, string>>  getLegalMoves (string color, map<pair<char, int>, pair<Pieces*, bool>> &board, Hueristic &H);
    
        void executeMove(pair<char, int> current, pair<char, int> wantedMove, map<pair<char, int> , pair<Pieces*, bool>> &board, Hueristic &H);
    

        map<pair<char, int>, pair<Pieces*, bool>> cloneBoard (map<pair<char, int>, pair<Pieces*, bool>> &board, Hueristic &cloneH);
        void destructBoard (map<pair<char, int>, pair<Pieces*, bool>> &board);
    
        int Min (map<pair<char, int>, pair<Pieces*, bool>> &board, int depth, int initialHeight, int beta, int alpha, Hueristic &H);
        int Max (map<pair<char, int>, pair<Pieces*, bool>> &board, int depth, int initialHeight, int beta, int alpha, Hueristic &H);
    
        bool isPieceSafe(map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &coord);
        bool kingInCheck(map<pair<char, int>, pair<Pieces*, bool>> &board, const pair<char, int> &Kcoord);
    
        double piecePositionReEval(Pieces* piece);
    
    
        double evaluateBoard(map<pair<char, int>, pair<Pieces*, bool>> &board);
    
    private:
    
        vector<Pieces*> whitePieces;
        vector<Pieces*> blackPieces;
        string CPUcolor;
    
};

