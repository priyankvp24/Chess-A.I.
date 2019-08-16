//
//  AI_engine.cpp
//  CHESS
//
//  Created by Priyank Patel on 8/13/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "AI_engine.hpp"

void MiniMax(map<pair<char, int>, pair<Pieces*, bool>> &board, int depth, int initialHeight, Hueristic &scaling) {
    cout << "Thinking..." << endl;
    
    int beta;
    int alpha;
    
    if (scaling.get_CPUcolor() == "white") {
        scaling.Min(board, depth, initialHeight, beta, alpha, scaling);
    }
    
    else {
        scaling.Max(board, depth, initialHeight, beta, alpha, scaling);
    }
    
    cout << "Beat that!" << endl;
    
    
}

