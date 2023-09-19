//
//  Classes.cpp
//  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//

#include "Classes.hpp"
#include <SFML/Graphics.hpp>

//Cat constuctor
Cat::Cat() {
    catShape.setSize(sf::Vector2f(50, 50)); // Cat's size
    catShape.setFillColor(sf::Color::Red); // Cat's color
    catShape.setPosition(100, 100);
}
//Mouse constructor
Mouse::Mouse() {
    mouseShape.setRadius(20); // Mouse's radius
    mouseShape.setFillColor(sf::Color::Green); // Mouse's color
    mouseShape.setPosition(400, 300); // Sets initial position
}
 sf::RectangleShape Cat::getShape() {
    return catShape;
 }

//move left by 5 pixels
void Cat::moveLeft() {
    catShape.move(-5, 0); 
}
//move right by 5 pixels
void Cat::moveRight() { 
    catShape.move(5, 0);
}
//move up by 5 pixels
void Cat::moveUp() {
    catShape.move(0, -5);
}
void Cat::moveDown() {
    catShape.move(0, 5);
}
/* Mouse cpp-------------------------------------*/
void Mouse::moveRandomly() {
    
}
