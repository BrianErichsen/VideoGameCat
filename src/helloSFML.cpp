#include <SFML/Graphics.hpp>
#include "Classes.hpp"

int main()
{
    // Creates the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    // Creates instances of the cat and mouse
    Cat cat;
    Mouse mouse;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        //handle user input to control cat
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            cat.moveLeft();
        }
        mouse.moveRandomly();
        window.clear();
        //Draws the cat and the mouse
        window.draw(cat.getShape());
        // window.draw(mouse.getShape());
	// end the current frame
        window.display();
        }

    return 0;
}
