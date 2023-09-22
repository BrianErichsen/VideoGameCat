#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "Classes.hpp"
#include "Mouse.hpp"
#include <ctime>
#include <string>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    // Seed the random number generator
    Game game(1200, 700, "CHASING GAME");
    game.run();
    return 0;
}
// int main()
// {
//     // Create the window
//     sf::RenderWindow window(sf::VideoMode(1200, 700), "CHASING GAME");
//     window.setFramerateLimit(60);

//     // Load the background image
//     sf::Texture backgroundTexture;
//     if (!backgroundTexture.loadFromFile("/Users/brianerichsenfagundes/Desktop/background.jpg")) {
//         // Handle the case where the image couldn't be loaded
//         return 1; // Exit with an error code
//     }
//     sf::Sprite backgroundSprite(backgroundTexture);

//     // Load the background music
//     sf::Music backgroundMusic;
//     if (!backgroundMusic.openFromFile("/Users/brianerichsenfagundes/Desktop/track.mp3")) {
//         // Handle the case where the audio file couldn't be loaded
//         return 1; // Exit with an error code
//     }
//     backgroundMusic.setVolume(50); // Adjust volume as needed
//     backgroundMusic.setLoop(true); // Keep song playing in a loop
//     backgroundMusic.play(); // Start playing the background song

//     // Load the mouse texture
//     sf::Texture mouseTexture;
//     if (!mouseTexture.loadFromFile("/Users/brianerichsenfagundes/Desktop/mouse.png")) {
//         return 1; // Handle the case where the image couldn't be loaded
//     }

//     // Create the mouse object
//     Mouse mouse(mouseTexture); // Initialize with the window size

//     // Create the cat player
//     Cat cat(2.0f);

//     // Initialize random seed based on current time
//     std::srand(static_cast<unsigned>(std::time(nullptr)));

//     // Timer for the game duration (30 seconds)
//     sf::Clock gameTimer;
//     bool gameWon = false;
//     bool gameLost = false;

//     // Initialize a timer and a random time interval
//     sf::Clock timer;
//     int interval = rand() % 5 + 2;
//     // To run the program as long as the window is open.
//     while (window.isOpen())
//     {
//         // Handle window events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close(); // Close the window on 'close requested' event
//             }
//         }
//         // Handle user input to control cat using cat.move()
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
//             sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
//             sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
//             sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//         {
//             cat.move(window);
//         }

//         // Calculate delta time
//         sf::Time dt = gameTimer.restart();

//          // Get the window size
//         sf::Vector2u windowSize = window.getSize();

//         // Check if it's time to move the mouse
//         if (timer.getElapsedTime().asMilliseconds() > interval)
//         {
//             mouse.updatePosition(dt, windowSize);
//         }

//         // Check for collisions
//         if (cat.shape.getGlobalBounds().intersects(mouse.getSprite().getGlobalBounds()) && !gameLost)
//         {
//             gameWon = true;
//             gameLost = false;
//         }

//         // Check if the game duration exceeds 30 seconds
//         if (gameTimer.getElapsedTime().asSeconds() > 30 && !gameWon)
//         {
//             gameWon = false;
//             gameLost = true;
//         }

//         window.clear();
//         window.draw(backgroundSprite);

//         // Draw game elements
//         if (gameWon)
//         {
//             // Display win message
//             sf::Font font;
//             if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf"))
//             {
//                 sf::Text winText("You Won!", font, 50);
//                 winText.setFillColor(sf::Color::Green);
//                 winText.setPosition(500, 300);
//                 window.draw(winText);
//             }
//         }
//         else if (gameLost)
//         {
//             // Display lose message
//             sf::Font font;
//             if (font.loadFromFile("/Users/brianerichsenfagundes/Desktop/arial.ttf"))
//             {
//                 sf::Text loseText("You Lost!", font, 50);
//                 loseText.setFillColor(sf::Color::Red);
//                 loseText.setPosition(500, 300);
//                 window.draw(loseText);
//             }
//         }
//         else
//         {
//             // Draw game objects
//             window.draw(cat.shape);
//             window.draw(mouse.getSprite());
//         }

//         window.display();
//     }

//     return 0;
// }
