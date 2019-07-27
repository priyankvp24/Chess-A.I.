//
//  Game.cpp
//  CHESS
//
//  Created by Priyank Patel on 7/17/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Game.hpp"


void Game :: playGame() {
    
}

void Game :: setUpBoard(sf::RenderWindow &window) {
    
    sf::Texture desk;
    if (!desk.loadFromFile("wooden.jpg")) {
        cout << "ERROR OPENING DESK" << endl;
    }
    sf::Sprite woodDesk;
    woodDesk.setTexture(desk);
    woodDesk.setPosition(0, 0);
    window.draw(woodDesk);
    
    //*****chess board font*****
    sf::Font gameFont;
    if (!gameFont.loadFromFile("ESCAMPURENAK.ttf")) {
        cout << "ERROR OPENING LETTERS" << endl;
    }
    
    //*****GameTitle*****
    sf::Text title;
    title.setFont(gameFont);
    title.setString("Checkmate!");
    title.setCharacterSize(100);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setPosition(1000, 60);
    window.draw(title);
    
    
    //*****The chess board*****
    //all the rows
    for(int i = 0; i < 8; ++i) {
        //initial coordinate variables
        int verticalPos = 250 + (150 * i);
        int FirstSquareIndex = 0;
        int SecondarySquareIndex = 1;
        //column of numbers
        sf::Text numbers;
        numbers.setFont(gameFont);
        char Num = (49 + i);
        numbers.setString(Num);
        numbers.setPosition(210, 300 + (150 * i));
        window.draw(numbers);
        
        //the columns
        for (int j = 0; j < 4; ++j) {
            //row of letters
            if (i == 0) {
                sf::Text letter1;
                sf::Text letter2;
                letter1.setFont(gameFont);
                letter2.setFont(gameFont);
                char firstLetter = (65 + FirstSquareIndex);
                char secondLetter = (65 + SecondarySquareIndex);
                letter1.setString(firstLetter);
                letter2.setString(secondLetter);
                letter1.setPosition(320 + (150 * FirstSquareIndex), 210);
                letter2.setPosition(320 + (150 * SecondarySquareIndex), 210);
                window.draw(letter1);
                window.draw(letter2);
            }
            //creating the rose squares
            sf::RectangleShape roseSquares (sf::Vector2f(150.f, 150.f));
            roseSquares.setFillColor(sf::Color(75,1,1));
            //creating the ivory squares
            sf::RectangleShape ivorySquares (sf::Vector2f(150.f, 150.f));
            ivorySquares.setFillColor(sf::Color(251,243,211));
            //if even have rose squares first
            if (i % 2 == 0) {
                roseSquares.setPosition(250 + (150 * FirstSquareIndex), verticalPos);
                ivorySquares.setPosition(250 + (150 * SecondarySquareIndex) , verticalPos);
            }
            //if odd have ivory squares first
            if (i % 2 != 0) {
                roseSquares.setPosition(250 + (150 * SecondarySquareIndex), verticalPos);
                ivorySquares.setPosition(250 + (150 * FirstSquareIndex) , verticalPos);
            }
            window.draw(roseSquares);
            window.draw(ivorySquares);
            //update square positioning
            FirstSquareIndex += 2;
            SecondarySquareIndex += 2;
            
        }
    }
    
}

void Game::isKingDead(sf::RenderWindow &window, const map<pair<char, int>, pair<Pieces*, bool>> &board, string checkColor, string otherColor) {
    
    map<pair<char, int>, pair<Pieces*, bool>> :: const_iterator i;
    
    bool isDead = true;
    
    for (i = board.begin(); i != board.end(); ++i) {
        
        if (((*i).second).second && ((*i).second).first->get_name() == "King" &&
            ((*i).second).first->get_color() == checkColor) {isDead = false;}
        
    }
    
    if (isDead) {
        
        sf::Font gameFont;
        if (!gameFont.loadFromFile("ESCAMPURENAK.ttf")) {
            cout << "ERROR OPENING LETTERS" << endl;
        }
        
        sf::Text winnerMsg;
        sf::Text winnerMsg2;
        winnerMsg2.setFont(gameFont);
        winnerMsg.setFont(gameFont);
        winnerMsg2.setString("The winner is " + otherColor);
        winnerMsg.setString("Checkmate!");
        winnerMsg2.setCharacterSize(100);
        winnerMsg.setCharacterSize(100);
        winnerMsg2.setStyle(sf::Text::Bold);
        winnerMsg.setStyle(sf::Text::Bold);
        winnerMsg2.setPosition(1600, 900);
        winnerMsg.setPosition(1800, 700);
        window.draw(winnerMsg);
        window.draw(winnerMsg2);

    }

}

