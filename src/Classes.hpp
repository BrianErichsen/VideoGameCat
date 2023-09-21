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
#include <SFML/Audio.hpp>

class Cat {
public:
    Cat(float moveSpeed);
    void move(sf::RenderWindow& Window);
    sf::CircleShape& getShape();
    sf::CircleShape shape;

private:
    float speed;
};
#endif /* Classes_hpp */
