#ifndef Mouse_hpp
#define Mouse_hpp
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


// class Mouse {
// public:
//     Mouse(const sf::Texture& texture);
//     void setPosition(const sf::Vector2f& position);
//     sf::Vector2f getPosition() const;
//     sf::Sprite getSprite() const;
//     void updatePosition(const sf::Time& dt, const sf::Vector2u& windowSize);
// private:
//     sf::Sprite sprite;
//     sf::Vector2f targetPosition;
//     sf::Clock moveTimer;
//     int moveInterval;
// };

class Mouse {
public:
    //Constructor for the Mouse class that is used to initialize a Mouse object when it's created.
    /*sf::Vector2u of SFML represents a two-dimensional vector of unsigned integers.*/
    Mouse(const sf::Vector2u& windowSize);
    
    // Function to update the position of the mouse.
    //deltaTime is the time elapsed since the last frame.
    void updatePosition(float deltaTime, const sf::Vector2u& windowSize);
    /*The first const indicates that the returned sprite is read-only, and the last const indicates that this function does not modify the internal state of the object it's called on*/
    //getter method to access sprite.
    const sf::Sprite& getSprite() const;
private:
    // The following variables are used to define the properties and state of a mouse.
    
    // 'sf::Texture texture;' is a variable that holds the texture (image data)
    sf::Texture texture;
    
    // 'sf::Sprite sprite;' is a variable that represents the sprite (2D image) using associated texture.
    sf::Sprite sprite;
    
    // 'sf::Vector2f position;' is a variable that defines the current position of the mouse.
    sf::Vector2f position;
    
    // 'sf::Vector2f destination;' is a variable that represents the target or destination position.
    sf::Vector2f destination;
    
    // 'sf::Clock moveTimer;' is a variable that is used to keep track of time, often for measuring
    //   the time elapsed since a specific event, such as the last movement of the mouse.
    sf::Clock moveTimer;
    
    // 'float moveSpeed;' is a variable that specifies the speed or rate at which the mouse moves.
    float moveSpeed;
};



#endif  