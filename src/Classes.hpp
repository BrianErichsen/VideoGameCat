//
//  Classes.hpp
// #pragma once //  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//

// #ifndef Classes_hpp
// #define Classes_hpp
// #include <stdio.h>
// #include <SFML/Graphics.hpp>
// #include <random>
// #include <ctime>
// class Cat {
// public:
//     Cat(); //Constructor
//     Cat(sf::Texture&); //Overload Constructor
//     ~Cat(); //Destructor

//     //Declare directions
//     enum _Direction{ Down, Left, Right, Up};

//     //Animation data
//     float _Speed; // Cat's speed
//     sf::Clock _AnimClock; //Cat's animation clock
//     sf::Time _AnimeTime; //Cat's animation time

//     void move(sf::RenderWindow& window);
//     void moveLeft();
//     void moveRight();
//     void moveUp();
//     void moveDown();
//     void setSpeed(float, sf::Time);
//     //SFML uses namespace called 'sf' to encapsulate classes and types
//     sf::RectangleShape getShape();
// private:
//     sf::RectangleShape catShape;

//     sf::RenderWindow window;
// };
// class Mouse {
// public:
//     Mouse(); //Constructor
//     void moveRandomly();
//     sf::CircleShape getShape();
    
// private:
//     sf::CircleShape mouseShape;
//     std::mt19937 rng;
// };
#endif /* Classes_hpp */
