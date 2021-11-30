#include "./Player/Player.hpp"
#include "./Asteroid/Asteroid.hpp"

#define WIDTH 1920
#define HEIGHT 1080
// #define WIDTH 800
// #define HEIGHT 500
int main()
{
    srand(time(NULL)); // Pour avoir des vraies nombres plus ou moins aléatoire

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Asteroids");
    window.setFramerateLimit(60);
    // RectangleShape shape(Vector2f(120, 50));

    // Initiation des classes
    Player *player = new Player();
    Asteroid *ast = new Asteroid();


    // Window's Game
    while (window.isOpen())
    {

        // Check Input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            player->input(event);
        }

        // Update Game
        player->Update();
        ast->Update();

        // Reset screen
        window.clear();

        // Draw game
        player->draw(window);
        ast->Draw(window);
        window.display();
    }

    delete player;
    delete ast; 

    return 0;
}