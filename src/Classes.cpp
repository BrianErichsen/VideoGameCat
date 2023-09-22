//
//  Classes.cpp
//  
//
//  Created by Brian Erichsen Fagundes on 9/18/23.
//
#include "Classes.hpp"
#include "Mouse.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Cat constructor
Cat::Cat(float speed)
    : moveSpeed(speed) {
    if (!texture.loadFromFile("/Users/brianerichsenfagundes/Desktop/cat.png")) {
        // Handle texture loading error
    }
    sprite.setTexture(texture);
    //Sets initial position of the cat
    position = sf::Vector2f(700.f, 400.f);
    sprite.setPosition(position);
}
void Cat::setPosition(const sf::Vector2f& newPosition) {
    //sets new position for the cat
    position = newPosition;
    sprite.setPosition(position);
}
//handles input based on keybinds and delta time
void Cat::move(float deltaTime, bool moveLeft, bool moveRight, bool moveUp, bool moveDown, const sf::Vector2u& windowSize) {
    if (moveLeft) {
        position.x -= moveSpeed * deltaTime;
    }
    if (moveRight) {
        position.x += moveSpeed * deltaTime;
    }
    if (moveUp) {
        position.y -= moveSpeed * deltaTime;
    }
    if (moveDown) {
        position.y += moveSpeed * deltaTime;
    }
    //Ensures that cat stays within screen and does not go off screen
    if (position.x < 0.f) {
        position.x = 0.f; //left
    } 
    //right
    if (position.x > windowSize.x - sprite.getGlobalBounds().width) {
        position.x = windowSize.x - sprite.getGlobalBounds().width;
    } 
    //If the cat goes too far up, it does not move further
    if (position.y < 0.f) {
        position.y = 0.f;
    }
    //If the cat goes too far down
    if (position.y > windowSize.y - sprite.getGlobalBounds().height) {
        position.y = windowSize.y - sprite.getGlobalBounds().height;
    }
    //Sets the new cat position of the cat sprite
    sprite.setPosition(position);
}
const sf::Sprite& Cat::getSprite() const {
    return sprite;
}
//Background function takes color as parameter and returns the background with the provided color and predetermined size.
Background::Background(const sf::Color& color) {
    //Size fo the background.
    background.setSize(sf::Vector2f(1200.f, 700.f));
    //Color of the background.
    background.setFillColor(color);
}
//getBackground function is a getter method that provides read-only access to the background member variable
const sf::RectangleShape& Background::getBackground() const {
    return background;
}
//Game constructor
Game::Game(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title),
      background(sf::Color::White),
      cat(80.f),
      mouse(window.getSize()),
      gameWon(false),
      gameLost(false) {
    window.setFramerateLimit(60);
    loadBackgroundMusic();
}
void Game::loadBackgroundMusic () {
    if (!backgroundMusic.openFromFile("/Users/brianerichsenfagundes/Desktop/track.mp3")) {
    }
    //Sets background music volume, and loops track
    backgroundMusic.setVolume(50);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}
void Game::run() {
    //Clock to measure time per frame
    sf::Clock frameClock; 
    float deltaTime = 0.0f; //Initialize deltaTime to 0 initially
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); //Close the window if close event is triggered
            }
        }
        //gets the time since last frame
        float frameTime = frameClock.restart().asSeconds();
        //Accumulate the elapsed time
        deltaTime += frameTime;
        //Caps deltaTime to a max value to avoid large steps
        const float maxDeltaTime = 0.1f;
        if (deltaTime > maxDeltaTime) {
            deltaTime = maxDeltaTime;
        }
        // Handle cat movement with arrow keys
        bool moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        bool moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        cat.move(deltaTime, moveLeft, moveRight, moveUp, moveDown, window.getSize());
        // Update mouse position and checks if cat positions is within or by mouse position
        mouse.updatePosition(deltaTime, window.getSize());
        //Sprite represents visual representation of cat and it access the mouse's visual representation
        //globalBounds returns floatRect or global bounding of the sprite
        if (cat.getSprite().getGlobalBounds().intersects(mouse.getSprite().getGlobalBounds())) {
            // Cat caught the mouse
            gameWon = true;
        }
        // Check if the game duration exceeds 30 seconds
        if (gameTimer.getElapsedTime().asSeconds() >= 30 && !gameWon) {
            // Cat did not catch the mouse in 30 seconds
            gameWon = false;
            gameLost = true;
        }
        window.clear();
        window.draw(background.getBackground());
        if (gameWon) {
            // Display win message
            sf::Font font;
            if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf")) {
                sf::Text winText("You Won!", font, 50);
                winText.setFillColor(sf::Color::Black);
                winText.setPosition(500, 350);
                window.draw(winText);
            }
        } else if (gameLost) {
            // Display lose message
            sf::Font font;
            if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf")) {
                sf::Text loseText("You Lost!", font, 50);
                loseText.setFillColor(sf::Color::Black);
                loseText.setPosition(500, 350);
                window.draw(loseText);
            }
        } else {
            window.draw(cat.getSprite());
            window.draw(mouse.getSprite());
        }
        window.display();
    }
}