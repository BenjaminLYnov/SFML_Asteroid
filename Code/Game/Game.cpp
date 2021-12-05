#include "Game.hpp"

Game::Game()
{
    srand(time(NULL)); // To get new alea number at each lauching

    gameEngine = new GameEngine();
    gameOverEngine = new GameOverEngine();

    window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Asteroids");
    window->setFramerateLimit(60); // Block game at 60 FPS
}

Game::~Game()
{
    delete window;
    delete gameEngine;
    delete gameOverEngine;
}

void Game::Run()
{
    sf::Event event;

    // Window's Game
    while (window->isOpen())
    {
        // Check Event
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            // Write pseudo while is Game Over
            gameOverEngine->WritePseudo(event, gameEngine->GetScore());
        }

        // After pseudo and score are saved, close game after 3 secondes
        CloseGame();

        // Reset screen
        window->clear();

        // If player is dead (hp fallen down to 0), let's moving to Game Over step
        if (gameEngine->PlayerIsDead())
            gameOverEngine->GameOver(true);

        if (!gameOverEngine->GetIsOver())
        {
            // Update Game Logic
            gameEngine->Update(*window);

            // Show game on the window
            gameEngine->Draw(*window);
        }
        else
            gameOverEngine->Draw(*window);

        window->display();
    }
}

void Game::CloseGame()
{
    if (gameOverEngine->GetIsSaved())
        ClosingGameTimer.UpTime();

    if (ClosingGameTimer.GetTime() > 3)
        window->close();
}
