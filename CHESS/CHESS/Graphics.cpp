//
//  Graphics.cpp
//  CHESS
//
//  Created by Priyank Patel on 6/9/19.
//  Copyright © 2019 Priyank Patel. All rights reserved.
//

#include "Graphics.hpp"


//we input a texture, by refrence, and the associate filename that texture will associate
//with this function uses error handling to ensure that the file was properly loaded to
//the texture
void textureLoader (sf::Texture &t, string file_name) {

    try {
        if(!t.loadFromFile(file_name)) {
            exception e;
            throw e;
        }
    }
    
    catch (exception e) {
        cout << file_name << " error" << endl;
    }
    
}
