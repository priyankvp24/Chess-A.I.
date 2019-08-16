//
//  Pieces_header.hpp
//  CHESS
//
//  Created by Priyank Patel on 8/2/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#ifndef Pieces_header_hpp
#define Pieces_header_hpp

#include <stdio.h>

#endif /* Pieces_header_hpp */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Graphics.hpp"
#pragma once
using namespace std;

const double pawnPositionEval[8][8] = {{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0},
    {1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0},
    {0.5, 0.5, 1.0, 2.5, 2.5, 1.0, 0.5, 0.5},
    {0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0},
    {0.5, -0.5, -1.0, 0.0, 0.0, -1.0, -0.5, 0.5},
    {0.5, 1.0, 1.0, -2.0, -2.0, 1.0, 1.0, 0.5},
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}};

const double knightPositionEval[8][8] = {{-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0},
    {-4.0, -2.0, 0.0, 0.0, 0.0, 0.0, -2.0, -4.0},
    {-3.0, 0.0, 1.0, 1.5, 1.5, 1.0, 0.0, -3.0},
    {-3.0, 0.5, 1.5, 2.0, 2.0, 1.5, 0.5, -3.0},
    {-3.0, 0.0, 1.5, 2.0, 2.0, 1.5, 0.0, -3.0},
    {-3.0, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -3.0},
    {-4.0, -2.0, 0.0, 0.5, 0.5, 0.0, -2.0, -4.0},
    {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0}};

const double bishopPositionEval[8][8] = {{-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0},
    {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
    {-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0},
    {-1.0, 0.5, 0.5, 1.0, 1.0, 0.5, 0.5, -1.0},
    {-1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, -1.0},
    {-1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0},
    {-1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, -1.0},
    {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}};

const double rookPositionEval[8][8] = {{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
    {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
    {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
    {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
    {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
    {-0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.5},
    {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0}};

const double queenPositionEval[8][8] = {{-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0},
    {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0},
    {-1.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0},
    {-0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -0.5},
    {0.0, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -0.5},
    {-1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0, -1.0},
    {-1.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, -1.0},
    {-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0}};

const double kingPositionEval[8][8] = {{-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
    {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
    {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
    {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
    {-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
    {-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
    {2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0},
    {2.0, 3.0, 1.0, 0.0, 0.0, 1.0, 3.0, 2.0}};

//use of the letter coordinate of a piece to calculate the exact x-value for the sprite
int xCoordinates(char letter);
//use of the letter coordinate of a piece to calculate the exact y-value for the sprite
int yCoordinates(int num);

class Pieces {
    
public:
    Pieces(string name_in, string color_init, char letter_init, int number_init,
            string file_name):
        letter(letter_init), number(number_init), name(name_in), color(color_init),
            fileName(file_name)
    {
        textureLoader(text,file_name);
        image.setTexture(text);
        update_sprite(xCoordinates(letter), yCoordinates(number));
        image.setScale(2.75, 2.75);
    }

    //VIRTUAL DECONSTRUCTOR TO ALLOW PROPER DECONSTRUCTION OF SUB-CLASSES
    virtual ~Pieces() {};
    
    //returns a piece's letter
    char get_letter();
    //returns a piece's number
    int get_number();
    //sets the piece's letter to given input
    void set_letter(char newChar);
    //sets the piece's number to given input
    void set_number(int newInt);
    //returns a piece's name
    string get_name();
    //returns a piece's color
    string get_color();
        //returns a piece's filename
    string get_filename();
    //returns a piece's sprite
    sf::Sprite& get_sprite();
    //update a sprites position on the board
    void update_sprite(int x, int y);
    //gives the possible moves if the entire board was empty
    virtual vector<pair<char, int>> possibleMovement() = 0;
    //gives the possible moves based on how other pieces are positioned on the board
    virtual vector<pair<char,int>> restrictedMovement(const vector<pair<char, int>> &possibleMoves, map<pair<char, int>, pair<Pieces*, bool>> &edited) = 0;
    virtual double findPositionReEval() = 0;
    
private:
    
    char letter;
    int number;
    string name;
    string color;
    string fileName;
    sf::Texture text;
    sf::Sprite image;
    
};


//returns pointers to Pieces that are dynamically sotred on the heap
Pieces * PieceFactory(string name,string color, char letter, int num, string file_name);
