#include "./Player/Player.hpp"
#include "./Obstacle/Asteroid.hpp"
#include <SFML/Graphics.hpp>

#define WIDTH 1920
#define HEIGHT 1080
// #define WIDTH 800
// #define HEIGHT 500

int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Astéroïds");
    window.setFramerateLimit(60);
    // RectangleShape shape(Vector2f(120, 50));

    // Initiation des classes
    Player player;
    Asteroid asteroid;

    // Window's Game
    while (window.isOpen())
    {

        // Check Input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            player.input(event);
        }

        // Update Game
        player.Update();
        asteroid.Update();

        // Reset screen
        window.clear();

        // Draw game
        player.draw(window);
        asteroid.draw(window);
        window.display();
    }
    return 0;
}