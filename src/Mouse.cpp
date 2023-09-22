#include "Mouse.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

//Define mouse constructor with initial speed of 100
Mouse::Mouse(const sf::Vector2u& windowSize)
    :moveSpeed(50.f) {
    //Make sure the picture is loaded.
    if (!texture.loadFromFile("/Users/brianerichsenfagundes/Desktop/mouse.png")) {
        std::cout<<"The mouse picture cannot be opened.";
    }
    /*Configure the appearance of the sprite by associating it with the texture, which will be used as the source of the image to be displayed on the screen.*/
    sprite.setTexture(texture);
    //Set the scale of the sprite.
    sprite.setScale(0.5f, 0.5f);
    //Initialize mouse position randomly within the window
    //rand() generates a random integer value/number.
    //windowSize.x is accessing the width component of the window's size.
    //getGlobalBounds() is a function that returns a sf::FloatRect representing the global bounding box of the sprite.
    /*windowSize.x - static_cast<int>(sprite.getGlobalBounds().width): This part calculates the range within which the random number should fall. It subtracts the width of the sprite's bounding box from the width of the game window, ensuring that the random X-coordinate doesn't place the sprite partially or completely outside the window.*/
    // Use modulo operator (%) to generate a random integer value within the specified range
    int randomX = rand() % (windowSize.x - static_cast<int>(sprite.getGlobalBounds().width));
    //Similar to rand x
    int randomY = rand() % (windowSize.y - static_cast<int>(sprite.getGlobalBounds().height));
    //Set the position (coordinates).
    position = sf::Vector2f(static_cast<float>(randomX), static_cast<float>(randomY));
    sprite.setPosition(position);
    // Generate a random destination for the mouse
    int destX = rand() % windowSize.x;
    int destY = rand() % windowSize.y;
    //Set the destination.
    destination = sf::Vector2f(static_cast<float>(destX), static_cast<float>(destY));
    //Track how much time has elapsed since the mouse started moving towards its destination
    moveTimer.restart();
}
void Mouse::updatePosition(float deltaTime, const sf::Vector2u& windowSize) {
    //Calculate the direction of the mouse.
    sf::Vector2f direction = destination - position;
    //length = sqrt(x^2 + y^2)
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    //Avoid dividing by zero
    /*Scale the horizontal component (x) of the direction vector by dividing it by the vector's length (length).It changes the vector's length to 1 while preserving its direction.*/
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }
    //Calculate the distance.
    float moveDistance = moveSpeed * deltaTime;
    sf::Vector2f newPosition = position + direction * moveDistance;
    // Check if the mouse has reached its destination
    if (length <= moveDistance) {
        newPosition = destination;
        // Generate a new random destination for the mouse
        int destX = rand() % static_cast<int>(windowSize.x - sprite.getGlobalBounds().width);
        int destY = rand() % static_cast<int>(windowSize.y - sprite.getGlobalBounds().height);
        destination = sf::Vector2f(static_cast<float>(destX), static_cast<float>(destY));
    }
    // Handle boundary collisions
    if (newPosition.x < 0.f || newPosition.x > windowSize.x - sprite.getGlobalBounds().width) {
        // Reverse the X direction
        direction.x = -direction.x;
    }
    if (newPosition.y < 0.f || newPosition.y > windowSize.y - sprite.getGlobalBounds().height) {
        // Reverse the Y direction
        direction.y = -direction.y;
    }
    /*"position + direction * moveDistance" adds the scaled direction vector to the current position vector. The result is a new position vector (newPosition) that represents where the object would be after moving by the specified distance in the specified direction.*/
    newPosition = position + direction * moveDistance;
    position = newPosition;
    sprite.setPosition(position);
}
//getter method to access sprite.
const sf::Sprite& Mouse::getSprite() const {
    return sprite;
}




