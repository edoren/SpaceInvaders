#include <SFML/Graphics.hpp>

#include <chrono>
#include <vector>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");

    sf::RectangleShape rectangle({10, 10});

    rectangle.setFillColor(sf::Color::White);

    std::vector<sf::RectangleShape> enemies;

    rectangle.setPosition({400 - 5, 300 - 5});

    // run the program as long as the window is open
    auto start = std::chrono::high_resolution_clock::now();
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        window.draw(rectangle);

        // end the current frame
        window.display();

        auto end = std::chrono::high_resolution_clock::now();
        start = end;
    }

    return 0;
}
