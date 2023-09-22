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
#include "Mouse.hpp"
class Cat {
public:
    Cat(float speed);
    //sets cat to 2D vector of unsigned integers
    void setPosition(const sf::Vector2f& newPosition);
    //handles user input and how fast it moves, delta time is time elapsed since last frame
    void move(float deltaTime, bool moveLeft, bool moveRight, bool moveUp, bool moveDown, const sf::Vector2u& windowSize);
    const sf::Sprite& getSprite() const;
private:
    sf::Texture texture; //holds image data
    sf::Sprite sprite; //represents the 2D image
    sf::Vector2f position; // defines position of the cat
    float moveSpeed;
};
class Background {
public:
    //This constructor initializes an instance of the Background class with a specified background color.
    //The color parameter cannot be modified within the constructor.
    Background(const sf::Color& color);
    
    /*The getBackground function serves the purpose of providing read-only access to the background rectangle (of type sf::RectangleShape). It allow external code to retrieve information about the background, such as its size or color.*/
    const sf::RectangleShape& getBackground() const;
private:
    //Member variable.
    sf::RectangleShape background;
};

class Game {
public:
    Game(int width, int height, const std::string& title); //constructor
    void run(); //Method to run the game
private:
    sf::RenderWindow window; //SFML window for rendering
    Background background; //Background object
    Cat cat; //Creates cat
    Mouse mouse; //Crates mouse
    sf::Clock gameTimer; //Timer for game duration
    //Flags to track when game is lost or won by user
    bool gameWon; 
    bool gameLost;
    //Loads background music while game is being played
    sf::Music backgroundMusic;
    void loadBackgroundMusic();
};
#endif /* Classes_hpp */
