#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "Classes.hpp"
#include <ctime>
int main()
{
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("/Users/brianerichsenfagundes/Desktop/track.mp3")) {
        // Handle the case where the image couldn't be loaded
        return 1; // Exit with an error code
    }
    backgroundMusic.setVolume(50); //Adjust volume as needed
    backgroundMusic.setLoop(true); //Keep song playing in a loop
    // Create the window
    sf::RenderWindow window(sf::VideoMode(1200, 700), "CHASING GAME");
    window.setFramerateLimit(60);
    // Load the background image
      sf::Texture backgroundTexture;
      if (!backgroundTexture.loadFromFile("/Users/brianerichsenfagundes/Desktop/background.jpg")) {
          // Handle the case where the image couldn't be loaded
          return 1; // Exit with an error code
      }
    sf::Sprite backgroundSprite(backgroundTexture);
    sf::RectangleShape
    rectangle(sf::Vector2f(30.f, 15.f));
    // Set the initial position of the rectangle
       sf::Vector2f rectanglePosition(200.f, 200.f);
       rectangle.setPosition(rectanglePosition);
    rectangle.setFillColor(sf::Color(0, 0, 0));
    
    // Initialize random seed based on current time
       std::srand(static_cast<unsigned>(std::time(nullptr)));
    // Timer for the game duration (30 seconds)
      sf::Clock gameTimer;
      bool gameWon = false;
      bool gameLost = false;

       // Initialize a timer and a random time interval
       sf::Clock timer;
       int interval = rand() % 5 + 2; 
       //Creates a cat player
    Cat cat(2.0f);
    //Start playing the background song
    backgroundMusic.play();

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
       // Handle user input to control cat using cat.move()
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
    	sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
    	sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
    	sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    	cat.move(window);
	}

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
        
        
        if (cat.shape.getGlobalBounds().intersects(rectangle.getGlobalBounds()) && !gameLost)
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
            window.draw(cat.shape);
            window.draw(rectangle);
        }
        backgroundMusic.stop();
        window.display();
    }
    return 0;
}