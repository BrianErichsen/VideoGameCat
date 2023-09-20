//
//  Classes.cpp
//  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//
// #include "Classes.hpp"
// #include <SFML/Graphics.hpp>
// #include <random>
// #include <ctime>
// //Cat constuctor
// Cat::Cat() {
//     catShape.setSize(sf::Vector2f(50, 50)); // Cat's size
//     catShape.setFillColor(sf::Color::Red); // Cat's color
//     catShape.setPosition(100, 100);
//     //Cats animation speed
//     _AnimeTime = sf::milliseconds(80); //Animation speed
//     _Speed = 0.20; //Player Speed
// }
// Cat::~Cat() 
// {
// }
// //Makes cat have a rectangule shape
//  sf::RectangleShape Cat::getShape() {
//     return catShape;
//  }
// //Sets key input to keybinds
// // void Cat::move(sf::RenderWindow& window) {
// // 	// Add logic to move the cat based on user input or game logic
// // 	// For example, you can handle arrow key input here
// // 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
// //         catShape.move(-5.f, 0.f);
// // 	}
// // 	// Add similar controls for other directions
 
// // 	// Ensure the cat stays within the window's boundaries
// // 	sf::Vector2f catPosition = catShape.getPosition();
// // 	catPosition.x = std::max(0.f, std::min(catPosition.x, static_cast<float>(window.getSize().x)));
// // 	catPosition.y = std::max(0.f, std::min(catPosition.y, static_cast<float>(window.getSize().y)));
// //     catShape.setPosition(catPosition);
// // }

// // move left by 5 pixels
// void Cat::moveLeft() {
//     // x the width and y the hight
//     //sf::Vector2f represents 2D points with floating point coordinate in Rectangles
//     //retrieves x and y of the cat's shape; stores it in currentPosition
//     sf::Vector2f currentPosition = catShape.getPosition();
//     //x component of size, represents width
//     float catWidth = catShape.getSize().x;
//     if (currentPosition.x > 0.f) {
//         catShape.move(-5.f, 0.f); //Move left by 5 pixels
//     }
// }
// void Cat::moveRight () {
//     sf::Vector2f currentPosition = catShape.getPosition();
//     float catWidth = catShape.getSize().x;
//     float windowWidth = static_cast<float>(window.getSize().x);

//     //Ensure that cat's position position stays on screnn
//     if (currentPosition.x > 0.f) {
//         catShape.move(-5.f, 0.f); //Move left by 5 pixels
//     } 
// }
// void Cat::moveUp () {
//     _Source.y = Up; //Sets it equal to 'Up' (_Direction Enum)
    
// }
    
// //move up by 5 pixels
// void Cat::moveUp() {
//     catShape.move(0, -5);
// }
// void Cat::moveDown() {
//     catShape.move(0, 5);
// }
/* Mouse cpp-------------------------------------*/
//Mouse constructor
// Mouse::Mouse() {
//     //Seed the random number generator with current time
//     rng.seed(std::time(nullptr));

//     mouseShape.setRadius(20); // Mouse's radius
//     mouseShape.setFillColor(sf::Color::Green); // Mouse's color
//     mouseShape.setPosition(400, 300); // Sets initial position
// }
// void Mouse::moveRandomly() {
//     std::uniform_int_distribution<int> dist(-5, 5);
//     int offsetX = dist(rng); //value between -5 and 5
//     int offsetY = dist(rng); // value between -5 and 5
//     mouseShape.move(offsetX, 0);
//     mouseShape.move(0, offsetY);
// }

//  sf::CircleShape Mouse::getShape() {
//     return mouseShape;
//  }
