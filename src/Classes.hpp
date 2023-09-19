//
//  Classes.hpp
// #pragma once //  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//

#ifndef Classes_hpp
#define Classes_hpp
#include <stdio.h>
#include <SFML/Graphics.hpp>
class Cat {
public:
    Cat(); //Constructor
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    //SFML uses namespace called 'sf' to encapsulate classes and types
    sf::RectangleShape getShape();
private:
    sf::RectangleShape catShape;
};
class Mouse {
public:
    Mouse(); //Constructor
    void moveRandomly();
    sf::CircleShape getShape();
private:
    sf::CircleShape mouseShape;
};
#endif /* Classes_hpp */
