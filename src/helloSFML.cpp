#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
int main()
{// Create the window
    sf::RenderWindow window(sf::VideoMode(1200, 700), "CHASING GAME");
    // Load the background image
      sf::Texture backgroundTexture;
      if (!backgroundTexture.loadFromFile("/Users/brianerichsenfagundes/Desktop/background.jpg")) {
          // Handle the case where the image couldn't be loaded
          return 1; // Exit with an error code
      }
    sf::Sprite backgroundSprite(backgroundTexture);
    
    // Create the circle (representing the cat)
    //Give the raduis of 40.
      sf::CircleShape shape(20.f);
    
    sf::RectangleShape
    rectangle(sf::Vector2f(30.f, 15.f));
    // Set the initial position of the rectangle
       sf::Vector2f rectanglePosition(200.f, 200.f);
       rectangle.setPosition(rectanglePosition);
    rectangle.setFillColor(sf::Color(0, 0, 0));
    
    //Set the color of the circle to black.
      shape.setFillColor(sf::Color::Black);
    // Set the initial position of the circle
      sf::Vector2f circlePosition(100.f, 100.f);
      shape.setPosition(circlePosition);
    //Set the speed at which the circle moves
    float moveSpeed = 1.f;
    // Create a flag to track whether the circle should move
    bool shouldMove = false;
    
    // Flags to track key states
    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;
    // Initialize random seed based on current time
       std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Timer for the game duration (30 seconds)
      sf::Clock gameTimer;
      bool gameWon = false;
      bool gameLost = false;
    
    
       // Initialize a timer and a random time interval
       sf::Clock timer;
       int interval = rand() % 5 + 2; 
    
    
    // To run the program as long as the window is open.
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
//Handle keyboard input to start/stop the circle's movement
        //Left arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            moveLeft = true;
        } else {
            moveLeft = false;
        }

        //Right arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            moveRight = true;
        } else {
            moveRight = false;
        }
        //Up arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            moveUp = true;
        } else {
            moveUp = false;
        }
        //Down arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            moveDown = true;
        } else {
            moveDown = false;
        }
        // Update the circle's position based on key states
        if (moveLeft) {
            circlePosition.x -= moveSpeed * 0.02f;
        }
        if (moveRight) {
            circlePosition.x += moveSpeed * 0.02f;
        }
        if (moveUp) {
            circlePosition.y -= moveSpeed * 0.02f;
        }
        if (moveDown) {
            circlePosition.y += moveSpeed * 0.02f;
        }
       // Only update the circle's position if it should move
       if (shouldMove) {
           // Update the circle's position
           shape.setPosition(circlePosition);
           shouldMove = false;
       }
        
// Keep the circle within the window
      if (circlePosition.x < 0.f) {
          circlePosition.x = 0.f;
      }
        /*circlePosition.x represents the current x-coordinate (horizontal position) of the circle in the window.
         window.getSize().x is the width of the window,or the right boundary.
         shape.getRadius() * 2.f calculates the diameter of the circle. This ensures that the entire circle fits within the window.*/
      if (circlePosition.x > window.getSize().x - shape.getRadius() * 2.f) {
          circlePosition.x = window.getSize().x - shape.getRadius() * 2.f;
      }
        /*The 0.f is used as a constant floating-point value representing the top boundary of the window. */
      if (circlePosition.y < 0.f) {
          circlePosition.y = 0.f;
      }
      if (circlePosition.y > window.getSize().y - shape.getRadius() * 2.f) {
          circlePosition.y = window.getSize().y - shape.getRadius() * 2.f;
      }
      // Update the circle's position
      shape.setPosition(circlePosition);
        
// Check if it's time to move the rectangle
    if (timer.getElapsedTime().asMilliseconds() > interval)
    {
        int randomX = rand() % (int)(window.getSize().x - rectangle.getSize().x);
        int randomY = rand() % (int)(window.getSize().y - rectangle.getSize().y);
        rectangle.setPosition(static_cast<float>(randomX), static_cast<float>(randomY));
        // Reset the timer and generate a new random interval
        timer.restart();
        interval = rand() % 5000 + 2000; // Random interval between 2 to 7 seconds
    } // Check if the circle and rectangle overlap (collision)
        
        
        if (shape.getGlobalBounds().intersects(rectangle.getGlobalBounds()) && !gameLost)
        {
            gameWon = true;
            gameLost = false;
        }
        // Check if the game duration exceeds 30 seconds
        if (gameTimer.getElapsedTime().asSeconds() > 30 && !gameWon)
        {
            gameWon = false;
            gameLost = true;
        }
        window.clear();
        window.draw(backgroundSprite);
        if (gameWon)
        {
            // Display win message
            sf::Font font;
            if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf")) {
                sf::Text winText("You Won!", font, 50);
                winText.setFillColor(sf::Color::Green);
                winText.setPosition(500, 300);
                window.draw(winText);
            }
        }
        else if (gameLost)
        {
            // Display lose message
            sf::Font font;
            if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf")) {
                sf::Text loseText("You Lost!", font, 50);
                loseText.setFillColor(sf::Color::Red);
                loseText.setPosition(500, 300);
                window.draw(loseText);
            }
        }
        else
        {
            window.draw(shape);
            window.draw(rectangle);
        }
        window.display();
    }
    return 0;
}

// #include <SFML/Graphics.hpp>
// #include "Classes.hpp"

// int main()
// {
//     // Creates the window
//     sf::RenderWindow window(sf::VideoMode(1200, 1200), "SaveTheCat");
//     window.setFramerateLimit(60);
//     // Creates instances of the cat and mouse
//     Cat cat;
//     Mouse mouse;

//     // run the program as long as the window is open
//     while (window.isOpen())
//     {
//         // check all the window's events that were triggered since the last iteration of the loop
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             // "close requested" event: we close the window
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }
//         // Clear the window with black color
//         window.clear(sf::Color::Black);
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
//         sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
//         sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
//         sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
//         cat.move(window);
//         }
//         mouse.moveRandomly();
//         //handle user input to control cat
//         // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//         //     cat.moveLeft();
//         // }
//         // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//         //     cat.moveRight();
//         // }
//         //  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//         //     cat.moveUp();
//         // }
//         // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//         //     cat.moveDown();
//         // }
//         window.clear(sf::Color::Black);
//         //Draws the cat and the mouse
//         window.draw(cat.getShape());
//         window.draw(mouse.getShape());
// 	// end the current frame
//         window.display();
//         }

//     return 0;
// }
