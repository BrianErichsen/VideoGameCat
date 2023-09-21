//
//  Classes.cpp
//  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//
#include "Classes.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
Cat::Cat(float moveSpeed) : speed(moveSpeed) {
    shape.setRadius(20.f);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(100.f, 100.f);
}
sf::CircleShape& Cat::getShape() {
    return shape;
}

void Cat::move(sf::RenderWindow& window) {
    sf::Vector2f currentPosition = shape.getPosition();
    
    //handles input from user to control the cat
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
    currentPosition.x > 0.f) {
        shape.move(-speed, 0.f); //Move left by speed pixels
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
    currentPosition.x + shape.getRadius() * 2.f < window.getSize().x) {
        shape.move(speed, 0.f); //Move right by speed pixels
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
    currentPosition.y > 0.f) {
        shape.move(0.f, -speed); //Move up by speed pixels
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
    currentPosition.y + shape.getRadius() * 2.f < window.getSize().y) {
        shape.move(0.f, speed); //Move Down by speed pixels
    }
}