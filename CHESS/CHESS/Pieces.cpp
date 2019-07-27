//
//  Pieces.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/9/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Pieces.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//returns a piece's letter
char Pieces::get_letter() {
    return letter;
}

//returns a piece's number
int Pieces::get_number() {
    return number;
}

//sets the piece's letter to given input
void Pieces::set_letter(char newChar) {
    letter = newChar;
}

//sets the piece's number to given input
void Pieces:: set_number(int newNum) {
    number = newNum;
}

//returns a piece's name
string Pieces::get_name() {
    return name;
}

//returns a piece's color
string Pieces::get_color() {
    return color;
}

//returns a piece's sprite
sf::Sprite Pieces::get_sprite() {
    return image;
}

//use of the letter coordinate of a piece to calculate the exact x-value for the sprite
int xCoordinates(char letter) {
    
    //array of possible letter on chess board
    char alphabet[8] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    //the location of 'A' on the chess board
    int x = 258;
    
    //traversing variable
    int i = 0;
    
    //itterate through alphabet, until the input letter equals and element in alphabet
    while (letter != alphabet[i]) {
        //the horizontal space between each sqaure on the board
        x += 150;
        ++i;
    }
    
    //return the x-value needed
    return x;
}

//use of the letter coordinate of a piece to calculate the exact y-value for the sprite
int yCoordinates(int num) {
    
    //array of possible numbers on the chess board
    int numbers[8] = {1 , 2, 3, 4, 5, 6, 7, 8};
    
    //the initial y-value of the number 1 on the chess board
    int y = 250;
    int i = 0;
    
    //itterate through numbers until we reach an element that equals num
    while (num != numbers[i]) {
        //the vertical space between each
        y += 150;
        ++i;
    }
    
    return y;
}

void Pieces::update_sprite(int x, int y) {
    image.setPosition(x, y);
}

bool isIncreasing (int current, int prev) {
    
    if (current > prev) {return true;}
    
    return false;
}

bool isDecreasing (int current, int prev) {
    
    if(prev > current) {return true;}
    
    return false;
}

class is_property {
    
    public:
    
    is_property(string prop): property(prop) {}
    
    bool operator() (int current, int prev) {
        
        if (property == "increasing") {
            
            if (current > prev) {return true;}
            
            return false;
        }
        
        else if (property == "decreasing") {
            
            if(prev > current) {return true;}
            
            return false;
            
        }
        
        return false;
    }
    
    private:
    
    string property;
    
    
};


//the sub-class pawn
class Pawn : public Pieces {
    
public:
    
    //pawn constructor
    Pawn(string name_in, string color_init, char letter_init, int number_init, string file_name):
    //calling the base class constructor
        Pieces(name_in, color_init, letter_init, number_init, file_name) {}
    
    //gives the possible movements of a given pawn, on empty board
    vector<pair<char, int>> possibleMovement() override{
        
        vector<pair<char, int>> possiblities;
        
        if (get_color() == "black") {
            
            pair<char, int> option1(get_letter(), get_number() - 1);
            possiblities.push_back(option1);
            
            if (get_letter() == 'A') {
                pair<char, int> optionKillAlt(get_letter() + 1, get_number() - 1);
                possiblities.push_back(optionKillAlt);
            }
            
            else if (get_letter() == 'H') {
                pair <char, int> optionKill(get_letter() - 1, get_number() - 1);
                possiblities.push_back(optionKill);
            }
            
            else {
                pair<char, int> optionKill(get_letter() - 1, get_number() - 1);
                pair<char, int> optionKillAlt(get_letter() + 1, get_number() - 1);
                possiblities.push_back(optionKill);
                possiblities.push_back(optionKillAlt);
            }
            
        }
        
        if (get_color() == "white") {
            
            pair<char, int> option1(get_letter(), get_number() + 1);
            possiblities.push_back(option1);
            
            if (get_letter() == 'A') {
                pair<char, int> optionKillAlt(get_letter() + 1, get_number() + 1);
                possiblities.push_back(optionKillAlt);
            }
            
            else if (get_letter() == 'H') {
                pair <char, int> optionKill(get_letter() - 1, get_number() + 1);
                possiblities.push_back(optionKill);
            }
            
            else {
                pair<char, int> optionKill(get_letter() - 1, get_number() + 1);
                pair<char, int> optionKillAlt(get_letter() + 1, get_number() + 1);
                possiblities.push_back(optionKill);
                possiblities.push_back(optionKillAlt);
            }
            
        }
        
        
        
        return possiblities;
        
    }
    
    //gives restriced motion of a pawn, based on its current situation and other pieces
    //near them
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        
        vector<pair<char, int>> finalCut;
        
        
        for (int i = 0; i < possibleMoves.size(); ++i) {
            
            pair<char, int> option(possibleMoves[i]);
            
            if (get_color() == "black") {
                
                if (i == 0 && get_number() == 7) {
                    
                    pair<char, int> twoStep(get_letter(), get_number()-2);
                    pair<char, int> beforeTwoStep(get_letter(), get_number()-1);
                    
                    if (!edited[twoStep].second && !edited[beforeTwoStep].second) {
                        finalCut.push_back(twoStep);
                    }
                    
                }
                
                if(edited[option].second == true && ((option.first == get_letter()-1 && option.second == get_number()-1) || (option.first == get_letter()+1 && option.second == get_number()-1)) && edited[option].first->get_color() == "white") {
                    
                    finalCut.push_back(option);
                }
                
                if(edited[option].second == false && (option.first == get_letter() && option.second == get_number()-1)) {
                    
                    finalCut.push_back(option);
                }
                
            }
            
            if (get_color() == "white") {
                
                if (i == 0 && get_number() == 2) {
                    
                    pair<char, int> twoStep(get_letter(), get_number()+2);
                    pair<char, int> beforeTwoStep(get_letter(), get_number()+1);
                    
                    if (!edited[twoStep].second && !edited[beforeTwoStep].second) {
                        finalCut.push_back(twoStep);
                    }
                    
                }
                
                if(edited[option].second == true && ((option.first == get_letter()-1 && option.second == get_number()+1) || (option.first == get_letter()+1 && option.second == get_number()+1)) && edited[option].first->get_color() == "black") {
                    
                    finalCut.push_back(option);
                }
                
                if(edited[option].second == false && (option.first == get_letter() && option.second == get_number()+1)) {
                    
                    finalCut.push_back(option);
                }
                
            }
   
        }
        
        return finalCut;
        
        
    }
    
   
    
};

//the sub-class rook
class Rook : public Pieces {
    
public:
    //the constructor of the rook class
    Rook(string name_in, string color_init, char letter_init, int number_init, string file_name):
    //initially calling the base class' constructor
        Pieces(name_in, color_init, letter_init, number_init, file_name) {}
    
    //give the possible movements of the rook on an empty board
    vector<pair<char, int>> possibleMovement() override {
        
        vector<pair<char, int>> possibilities;
        
        int goingUp = get_number() - 1;
        while(goingUp != 0) {
            pair<char, int> option1(get_letter(), goingUp);
            possibilities.push_back(option1);
            --goingUp;
        }
        
        char goingRight = get_letter() + 1;
        while(goingRight != 'I') {
            pair<char, int> option3(goingRight, get_number());
            possibilities.push_back(option3);
            ++goingRight;
        }
        
        int goingDown = get_number() + 1;
        while(goingDown != 9) {
            pair<char, int> option2(get_letter(),goingDown);
            possibilities.push_back(option2);
            ++goingDown;
        }
        
        char goingLeft = get_letter() - 1;
        while(goingLeft != '@') {
            pair<char, int> option4(goingLeft, get_number());
            possibilities.push_back(option4);
            --goingLeft;
        }
        
        return possibilities;
    }
    
    //gives the movments of a rook, based on the current board positioning and pieces
    //around it
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        vector<pair<char, int>> finalCut;
        
        int i = 0;
        
    
        while (possibleMoves[i].first == get_letter()) {
            
            if (edited[possibleMoves[i]].second) {
                
                if (get_color() == "white" && (edited[possibleMoves[i]].first->get_color() == "black")) {
                    
                    finalCut.push_back(possibleMoves[i]);
                }
                
                if (get_color() == "black" && (edited[possibleMoves[i]].first->get_color() == "white")) {
                    
                    finalCut.push_back(possibleMoves[i]);
                }
                
                while (possibleMoves[i].first == get_letter()) {
                    ++i;
                }
                
            }
            
            else {
                finalCut.push_back(possibleMoves[i]);
                ++i;
            }
            
        }
        

        while (possibleMoves[i].second == get_number()) {
            
            if (edited[possibleMoves[i]].second) {
                
                if (get_color() == "white" && (edited[possibleMoves[i]].first->get_color() == "black")) {
                    
                    finalCut.push_back(possibleMoves[i]);
                }
                
                if (get_color() == "black" && (edited[possibleMoves[i]].first->get_color() == "white")) {
                    
                    finalCut.push_back(possibleMoves[i]);
                }
                
                while (possibleMoves[i].second == get_number()) {
                    ++i;
                }
            
            }
            
            else {
                finalCut.push_back(possibleMoves[i]);
                ++i;
            }

            
        }

        while (possibleMoves[i].first == get_letter()) {
            
            if (edited[possibleMoves[i]].second) {
                
                if (get_color() == "white" && edited[possibleMoves[i]].first->get_color() == "black") {
                    finalCut.push_back(possibleMoves[i]);
                }
                
                if (get_color() == "black" && edited[possibleMoves[i]].first->get_color() == "white") {
                    finalCut.push_back(possibleMoves[i]);
                }
                
                while (possibleMoves[i].first == get_letter()) {
                    ++i;
                }
                
            }
            
            else {
                finalCut.push_back(possibleMoves[i]);
                ++i;
            }
            
            
        }
        

        while (i != possibleMoves.size()) {
            
            if (edited[possibleMoves[i]].second) {
                if (get_color() == "white" && edited[possibleMoves[i]].first->get_color() == "black") {
                    finalCut.push_back(possibleMoves[i]);
                }
                
                if (get_color() == "black" && edited[possibleMoves[i]].first->get_color() == "white") {
                    finalCut.push_back(possibleMoves[i]);
                }
                while (i != possibleMoves.size()) {
                    ++i;
                }
            }
            
            else {
                finalCut.push_back(possibleMoves[i]);
                ++i;
            }
            
        }
        
        
        return finalCut;
        
    }
    
};

//the sub-class bishop
class Bishop : public Pieces {
    
public:
    
    //the constructor of the bishop class
    Bishop(string name_in, string color_init, char letter_init, int number_init, string file_name):
     //initially calling the base class' constructor
        Pieces(name_in, color_init, letter_init, number_init, file_name) {}
    
    //give the possible movements of the bishop on an empty board
    vector<pair<char, int>> possibleMovement() override {
        
        vector<pair<char, int>> possibilities;
        
        //on the first diagonal
        pair<char, int> goingUp(get_letter(), get_number());
        pair<char, int> goingDown(get_letter(), get_number());
        
        //on the second diagonal
        pair<char, int> goingUp2(get_letter(), get_number());
        pair<char, int> goingDown2(get_letter(), get_number());
        
        if (goingUp.second == 1 || goingUp.first == 'H') {
            pair<char, int> northEast('#', 99);
            possibilities.push_back(northEast);
        }
        
        while (goingUp.second != 1 && goingUp.first != 'H') {
            goingUp.first++;
            goingUp.second--;
            pair<char, int> add(goingUp);
            possibilities.push_back(add);
            
            if (goingUp.second == 1 || goingUp.first == 'H') {
                pair<char, int> northEast('#', 99);
                possibilities.push_back(northEast);
            }
        }
        
        if (goingDown.second == 8 || goingDown.first == 'A') {
            pair<char, int> southWest('#', 99);
            possibilities.push_back(southWest);
        }
        
        while (goingDown.second != 8 && goingDown.first != 'A') {
            goingDown.first--;
            goingDown.second++;
            pair<char, int> add(goingDown);
            possibilities.push_back(add);
            
            if (goingDown.second == 8 || goingDown.first == 'A') {
                pair<char, int> southWest('#', 99);
                possibilities.push_back(southWest);
            }
            
        }
        
        if (goingUp2.second == 1 || goingUp2.first == 'A') {
            pair<char, int> northWest('#', 99);
            possibilities.push_back(northWest);
        }
        
        while (goingUp2.second != 1 && goingUp2.first != 'A') {
            goingUp2.second--;
            goingUp2.first--;
            pair<char, int> add(goingUp2);
            possibilities.push_back(add);
            
            if (goingUp2.second == 1 || goingUp2.first == 'A') {
                pair<char, int> northWest('#', 99);
                possibilities.push_back(northWest);
            }
        }
        
        if (goingDown2.second == 8 || goingDown2.first == 'H') {
            pair<char, int> southEast('#', 99);
            possibilities.push_back(southEast);
        }
        
        while (goingDown2.second != 8 && goingDown2.first != 'H') {
            goingDown2.second++;
            goingDown2.first++;
            pair<char, int> add(goingDown2);
            possibilities.push_back(add);
            
            if (goingDown2.second == 8 || goingDown2.first == 'H') {
                pair<char, int> southEast('#', 99);
                possibilities.push_back(southEast);
            }
        }
        
        return possibilities;
    }
    
    //gives the movments of a bishop, based on the current board positioning and pieces
    //around it
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        vector<pair<char, int>> finalCut;
        
        int i = 0;
        
        
        for (int j = 0; j < 4; ++j) {
            
            while (possibleMoves[i].first != '#') {
                
                if (!edited[possibleMoves[i]].second) {
                    
                    finalCut.push_back(possibleMoves[i]);
                    ++i;
                    
                }
                
                else {
                    
                    
                    if ((get_color() == "white" && edited[possibleMoves[i]].first->get_color() == "black") ||
                        (get_color() == "black" && edited[possibleMoves[i]].first->get_color() == "white")) {
                        
                        finalCut.push_back(possibleMoves[i]);
                        
                    }
                    
                    while (possibleMoves[i].first != '#') {++i;}
                    
                    
                }
                
            }
            
            ++i;
            
        }
        
        return finalCut;
    
    }
    
};

//the sub-class knight
class Knight : public Pieces {
    
public:
    //the constructor of the knight class
    Knight(string name_in, string color_in, char letter_init, int number_init, string file_name):
    //initially calling the base class' constructor
        Pieces(name_in, color_in, letter_init, number_init, file_name){}
    
    //give the possible movements of the knight on an empty board
    vector<pair<char, int>> possibleMovement() override {
        
        vector<pair<char, int>> possibilities;
        
        //upRight
        if (get_letter() != 'H' && get_number() > 2) {
            
            char let = get_letter() + 1;
            int num = get_number() - 2;
            pair<char, int> upRight(let, num);
            possibilities.push_back(upRight);
            
        }
        
        //upLeft
        if (get_letter() != 'A' && get_number() > 2) {
            
            char let = get_letter() - 1;
            int num = get_number() - 2;
            pair<char, int> upLeft(let, num);
            possibilities.push_back(upLeft);
            
        }
        
        //leftUp
        if (get_letter() > 66 && get_number() > 1) {
            
            char let = get_letter() - 2;
            int num = get_number() - 1;
            pair<char, int> leftUp(let, num);
            possibilities.push_back(leftUp);
            
        }
        
        //leftDown
        if (get_letter() > 66 && get_number() < 8) {
            
            char let = get_letter() - 2;
            int num = get_number() + 1;
            pair<char, int> leftDown(let, num);
            possibilities.push_back(leftDown);
            
        }
        
        //rightUp
        if (get_letter() < 71 && get_number() > 1) {
            
            char let = get_letter() + 2;
            int num = get_number() - 1;
            pair<char, int> rightUp(let, num);
            possibilities.push_back(rightUp);
            
        }
        
        //rightDown
        if (get_letter() < 71 && get_number() < 8) {
            
            char let = get_letter() + 2;
            int num = get_number() + 1;
            pair<char, int> rightDown(let, num);
            possibilities.push_back(rightDown);
            
        }
            
        //downRight
        if (get_letter() != 'H' && get_number() < 7) {
            
            char let = get_letter() + 1;
            int num = get_number() + 2;
            pair<char, int> downRight(let, num);
            possibilities.push_back(downRight);
            
        }
        
        //downLeft
        if (get_letter() != 'A' && get_number() < 7) {
            
            char let = get_letter() - 1;
            int num = get_number() + 2;
            pair<char, int> downLeft(let, num);
            possibilities.push_back(downLeft);
            
        }
        
        return possibilities;
    }
    
    //gives the movments of a knight, based on the current board positioning and pieces
    //around it
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        vector<pair<char, int>> finalCut;
        
        vector<pair<char, int>> :: const_iterator i;
        
        for (i = possibleMoves.begin(); i != possibleMoves.end(); ++i) {
            
            if (edited[(*i)].second && (edited[(*i)].first->get_color() != get_color())) {
                finalCut.push_back(*i);
            }
            
            if (!edited[(*i)].second) {finalCut.push_back(*i);}
            
        }
        
        return finalCut;
        
    }

    
};

//the sub-class queen
class Queen : public Pieces {
    
public:
    //the constructor of the queen class
    Queen(string name_in, string color_in, char letter_init, int number_init, string file_name):
    //initially calling the base class' constructor
        Pieces(name_in, color_in, letter_init, number_init, file_name){}
    
    //give the possible movements of the queen on an empty board
    vector<pair<char, int>> possibleMovement() override {
        
        vector<pair<char, int>> possibilities;
        
        int goingUpRook = get_number() - 1;
        if (goingUpRook == 0) {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        while(goingUpRook != 0) {
            pair<char, int> option1(get_letter(), goingUpRook);
            possibilities.push_back(option1);
            --goingUpRook;
        }
        
        if (goingUpRook == 0) {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        int goingDownRook = get_number() + 1;
        if (goingDownRook == 9) {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        while(goingDownRook != 9) {
            pair<char, int> option2(get_letter(),goingDownRook);
            possibilities.push_back(option2);
            ++goingDownRook;
        }
        
        if (goingDownRook == 9) {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        char goingRightRook = get_letter() + 1;
        if (goingRightRook == 'I') {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        while(goingRightRook != 'I') {
            pair<char, int> option3(goingRightRook, get_number());
            possibilities.push_back(option3);
            ++goingRightRook;
        }
        
        if (goingRightRook == 'I') {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        char goingLeftRook = get_letter() - 1;
        if (goingLeftRook == '@') {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        while(goingLeftRook != '@') {
            pair<char, int> option4(goingLeftRook, get_number());
            possibilities.push_back(option4);
            --goingLeftRook;
        }
        
        if (goingLeftRook == '@') {
            pair<char, int> pause('#', 99);
            possibilities.push_back(pause);
        }
        
        /***********************************************/
        
        //on the first diagonal
        pair<char, int> goingUp(get_letter(), get_number());
        pair<char, int> goingDown(get_letter(), get_number());
        
        //on the second diagonal
        pair<char, int> goingUp2(get_letter(), get_number());
        pair<char, int> goingDown2(get_letter(), get_number());
        
        if (goingUp.second == 1 || goingUp.first == 'H') {
            pair<char, int> northEast('#', 99);
            possibilities.push_back(northEast);
        }
        
        while (goingUp.second != 1 && goingUp.first != 'H') {
            goingUp.first++;
            goingUp.second--;
            pair<char, int> add(goingUp);
            possibilities.push_back(add);
            
            if (goingUp.second == 1 || goingUp.first == 'H') {
                pair<char, int> northEast('#', 99);
                possibilities.push_back(northEast);
            }
        }
        
        if (goingDown.second == 8 || goingDown.first == 'A') {
            pair<char, int> southWest('#', 99);
            possibilities.push_back(southWest);
        }
        
        while (goingDown.second != 8 && goingDown.first != 'A') {
            goingDown.first--;
            goingDown.second++;
            pair<char, int> add(goingDown);
            possibilities.push_back(add);
            
            if (goingDown.second == 8 || goingDown.first == 'A') {
                pair<char, int> southWest('#', 99);
                possibilities.push_back(southWest);
            }
            
        }
        
        if (goingUp2.second == 1 || goingUp2.first == 'A') {
            pair<char, int> northWest('#', 99);
            possibilities.push_back(northWest);
        }
        
        while (goingUp2.second != 1 && goingUp2.first != 'A') {
            goingUp2.second--;
            goingUp2.first--;
            pair<char, int> add(goingUp2);
            possibilities.push_back(add);
            
            if (goingUp2.second == 1 || goingUp2.first == 'A') {
                pair<char, int> northWest('#', 99);
                possibilities.push_back(northWest);
            }
        }
        
        if (goingDown2.second == 8 || goingDown2.first == 'H') {
            pair<char, int> southEast('#', 99);
            possibilities.push_back(southEast);
        }
        
        while (goingDown2.second != 8 && goingDown2.first != 'H') {
            goingDown2.second++;
            goingDown2.first++;
            pair<char, int> add(goingDown2);
            possibilities.push_back(add);
            
            if (goingDown2.second == 8 || goingDown2.first == 'H') {
                pair<char, int> southEast('#', 99);
                possibilities.push_back(southEast);
            }
        }
        
        return possibilities;
    }
    
    //gives the movments of a queen, based on the current board positioning and pieces
    //around it
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        vector<pair<char, int>> finalCut;
        
        int k = 0;
        
        
        for (int j = 0; j < 8; ++j) {
            
            while (possibleMoves[k].first != '#') {
                
                if (!edited[possibleMoves[k]].second) {
                    
                    finalCut.push_back(possibleMoves[k]);
                    ++k;
                    
                }
                
                else {
                    
                    
                    if ((get_color() == "white" && edited[possibleMoves[k]].first->get_color() == "black") ||
                        (get_color() == "black" && edited[possibleMoves[k]].first->get_color() == "white")) {
                        
                        finalCut.push_back(possibleMoves[k]);
                        
                    }
                    
                    while (possibleMoves[k].first != '#') {++k;}
                    
                    
                }
                
            }
            
            ++k;
            
        }
        
        return finalCut;
        
    }
    
    
};

//the sub-class king
class King : public Pieces {
    
public:
    
    //the constructor of the king class
    King(string name_in, string color_in, char letter_init, int number_init, string file_name):
    //initially calling the base-class' constructor
        Pieces(name_in, color_in, letter_init, number_init, file_name){}
    
    //gives the possible movement of the king, given an empty board
    vector<pair<char, int>> possibleMovement() override {
        
        vector<pair<char, int>> possibilities;
        
        int goingUpRook = get_number() - 1;
        if(goingUpRook != 0) {
            pair<char, int> option1(get_letter(), goingUpRook);
            possibilities.push_back(option1);
        }
        
        int goingDownRook = get_number() + 1;
        if(goingDownRook != 9) {
            pair<char, int> option2(get_letter(),goingDownRook);
            possibilities.push_back(option2);
        }
        
        char goingRightRook = get_letter() + 1;
        if(goingRightRook != 'I') {
            pair<char, int> option3(goingRightRook, get_number());
            possibilities.push_back(option3);
        }
        
        char goingLeftRook = get_letter() - 1;
        if(goingLeftRook != '@') {
            pair<char, int> option4(goingLeftRook, get_number());
            possibilities.push_back(option4);
        }
        
        //on the first diagonal
        pair<char, int> goingUp(get_letter(), get_number());
        pair<char, int> goingDown(get_letter(), get_number());
        
        //on the second diagonal
        pair<char, int> goingUp2(get_letter(), get_number());
        pair<char, int> goingDown2(get_letter(), get_number());
        
        if (goingUp.second != 1 && goingUp.first != 'H') {
            goingUp.first++;
            goingUp.second--;
            pair<char, int> add(goingUp);
            possibilities.push_back(add);
        }
        
        if (goingDown.second != 8 && goingDown.first != 'A') {
            goingDown.first--;
            goingDown.second++;
            pair<char, int> add(goingDown);
            possibilities.push_back(add);
        }
        
        if (goingUp2.second != 1 && goingUp2.first != 'A') {
            goingUp2.second--;
            goingUp2.first--;
            pair<char, int> add(goingUp2);
            possibilities.push_back(add);
        }
        
        if (goingDown2.second != 8 && goingDown2.first != 'H') {
            goingDown2.second++;
            goingDown2.first++;
            pair<char, int> add(goingDown2);
            possibilities.push_back(add);
        }
        
        return possibilities;
    }
    
    //the possible movements of the king given certain board situations and the positions
    //of other pieces
    vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) override  {
        
        vector<pair<char, int>> finalCut;
        
        vector<pair<char, int>> :: const_iterator i;
        
        for (i = possibleMoves.begin(); i != possibleMoves.end(); ++i) {
            
            if (edited[(*i)].second && (edited[(*i)].first->get_color() != get_color())) {
                finalCut.push_back(*i);
            }
            
            if (!edited[(*i)].second) {finalCut.push_back(*i);}
            
        }
        
        return finalCut;
        
    }
    
   
};


//returns pointers to Pieces that are dynamically sotred on the heap
Pieces * PieceFactory(string name,string color, char letter, int num, string file_name) {
    
    Pieces* addition = nullptr;
    
    if (name == "Pawn") {
        addition = new Pawn(name, color, letter, num, file_name);
    }
    if (name == "Rook") {
        addition = new Rook(name, color, letter, num, file_name);
    }
    
    if (name == "Bishop") {
        addition = new Bishop(name, color, letter, num, file_name);
    }
    
    if (name == "Knight") {
        addition = new Knight(name, color, letter, num, file_name);
    }
    
    if (name == "Queen") {
        addition = new Queen(name, color, letter, num, file_name);
    }
    
    if (name == "King") {
        addition = new King(name, color, letter, num, file_name);
    }
    
    return addition;
}

