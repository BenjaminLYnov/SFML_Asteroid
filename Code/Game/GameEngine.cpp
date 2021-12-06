#include "GameEngine.hpp"
#include <string>
#include <iostream>

GameEngine::GameEngine()
{
    player = new Player();
    asteroidEngine = new AsteroidEngine();
    uhd = new UHD();
    menu = new Menu();

    ovniSound = new SfmlAudio("ressources/Sound/Asteroid79 sound/saucerBig.wav");
    ovniSound->SetVolume(20);
    playOnceOvniSound = true;

    asteroidNumber = 4;
}

GameEngine::~GameEngine()
{
    delete player;
    delete asteroidEngine;
    delete uhd;
    delete menu;
    delete ovniSound;
}

void GameEngine::Update(sf::RenderWindow &window)
{
    // Update Game Logic

    menu->Update(window);

    if (menu->GameStarted() && !menu->GetIsPause())
    {
        SetupLevel();
        CreateOVNI();
        DammageStep();

        player->Update();
        asteroidEngine->Update();
        uhd->Update(player->GetHp());

        for (int i = 0; i < ovnis.size(); i++)
            ovnis[i].MoveOnTarget(player->GetShape().getPosition());
    }

    // Manage ovni sound
    ONVISound();

    // Stop ovni sound while game is paused
    if (menu->GetIsPause() || PlayerIsDead())
        ovniSound->Stop();
}

void GameEngine::Draw(sf::RenderWindow &window) const
{
    // Draw Game

    if (menu->GameStarted())
    {
        asteroidEngine->Draw(window);
        player->Draw(window);
        uhd->Draw(window, player->GetHp());
        for (int i = 0; i < ovnis.size(); i++)
            ovnis[i].Draw(window);
    }

    menu->Draw(window);
}

int GameEngine::GetScore()
{
    uhd->GetScore();
}

bool GameEngine::PlayerIsDead()
{
    if (player->GetHp() <= 0)
        return true;
    else
        return false;
}

void GameEngine::SetupLevel()
{
    if (asteroidEngine->GetAsteroids().size() == 0)
    {
        for (int i = 0; i < asteroidNumber; i++)
            asteroidEngine->CreateAsteroid();
        uhd->UpLevel();
        asteroidNumber += 2;
    }
}

void GameEngine::CreateOVNI()
{
    createOVNICoolDown.UpTime();
    if (createOVNICoolDown.GetTime() > 10)
    {
        ovnis.push_back(OVNI());
        createOVNICoolDown.Reset();
    }
}

void GameEngine::PlayerDammageOnAsteroid()
{
    int indiceLaser = 0;
    std::vector<int> indiceLaserToDestroy;
    for (auto laser : player->GetSkills().GetLasers())
    {
        for (int j = asteroidEngine->GetAsteroids().size() - 1; j >= 0; j--)
            // If Laser touch asteroid
            if (Collision::IsTrigger(laser.GetShape(), asteroidEngine->GetAsteroid(j).GetShape()))
            {
                asteroidEngine->GetAsteroid(j).PlayBangSound();
                if (asteroidEngine->GetAsteroid(j).GetSize() == 1)
                {
                    uhd->UpScore(50);
                    for (int i = 0; i < 2; i++)
                    {
                        asteroidEngine->CreateAsteroid(2);
                        asteroidEngine->GetLastAsteroid().GetShape().setPosition(asteroidEngine->GetAsteroid(j).GetShape().getPosition());
                    }
                }
                else if (asteroidEngine->GetAsteroid(j).GetSize() == 2)
                {
                    uhd->UpScore(30);
                    for (int i = 0; i < 2; i++)
                    {
                        asteroidEngine->CreateAsteroid(3);
                        asteroidEngine->GetLastAsteroid().GetShape().setPosition(asteroidEngine->GetAsteroid(j).GetShape().getPosition());
                    }
                }
                else
                    uhd->UpScore(10);

                asteroidEngine->DestroyAsteroid(j);
                indiceLaserToDestroy.push_back(indiceLaser);
                indiceLaser++;
            }

        // Erase laser
        for (int i = indiceLaserToDestroy.size() - 1; i >= 0; i--)
            if (player->GetSkills().GetLasers().size() > 0)
                player->GetSkills().GetLasers().erase(player->GetSkills().GetLasers().begin() + indiceLaserToDestroy[i]);
    }
}

void GameEngine::PlayerDammageOnOVNI()
{
    int indiceLaser = 0;
    std::vector<int> indiceLaserToDestroy;
    for (auto laser : player->GetSkills().GetLasers())
    {
        for (int j = ovnis.size() - 1; j >= 0; j--)
            // If Laser touch OVNI
            if (Collision::IsTrigger(laser.GetShape(), ovnis[j].GetShape()))
            {
                uhd->UpScore(100);
                ovnis.erase(ovnis.begin() + j);
                indiceLaserToDestroy.push_back(indiceLaser);
                indiceLaser++;
            }

        // Erase laser
        for (int i = indiceLaserToDestroy.size() - 1; i >= 0; i--)
            if (player->GetSkills().GetLasers().size() > 0)
                player->GetSkills().GetLasers().erase(player->GetSkills().GetLasers().begin() + indiceLaserToDestroy[i]);
    }
}

void GameEngine::AsteroidDammageOnPlayer()
{
    for (auto &asteroid : asteroidEngine->GetAsteroids())
        if (Collision::IsTrigger(player->GetShape(), asteroid.GetShape()))
            player->GetHurt();
}

void GameEngine::OVNIDammageOnPlayer()
{
    for (auto &ovni : ovnis)
        if (Collision::IsTrigger(player->GetShape(), ovni.GetShape()))
            player->GetHurt();
}

void GameEngine::DammageStep()
{
    PlayerDammageOnAsteroid();
    PlayerDammageOnOVNI();
    AsteroidDammageOnPlayer();
    OVNIDammageOnPlayer();
}

void GameEngine::ONVISound()
{
    if (ovnis.size() == 0)
    {
        playOnceOvniSound = true;
        ovniSound->Stop();
    }
    else if (playOnceOvniSound)
    {
        ovniSound->PlayLoop();
        playOnceOvniSound = false;
    }
}
