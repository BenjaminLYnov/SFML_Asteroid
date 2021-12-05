#include "ScoreManager.hpp"
#include <fstream>

int ScoreManager::GetHightestScore()
{
    std::ifstream file("ressources/scores.txt");
    int higthestScore = 0;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (GetScore(line) > higthestScore)
                higthestScore = GetScore(line);
        }
        file.close();
    }
    return higthestScore;
}

std::vector<int> ScoreManager::GetTopScore(int topNumber)
{
    std::ifstream file("ressources/scores.txt");
    std::vector<int> allScore;
    std::vector<int> higthestScores;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
            allScore.push_back(GetScore(line));
        file.close();
    }

    while (allScore.size() > 0)
    {
        if (higthestScores.size() == topNumber)
            break;

        for (int j = 0; j < allScore.size(); j++)
        {
            if (GetHightestNumber(allScore) == allScore[j])
            {
                higthestScores.push_back(allScore[j]);
                allScore.erase(allScore.begin() + j);
                j = 0;
            }
        }
    }
    return higthestScores;
}

std::vector<std::string> ScoreManager::GetTopPseudo(int topNumber)
{
    std::ifstream file("ressources/scores.txt");
    std::vector<int> allScore;
    std::vector<std::string> topPseudo;
    int numberScore;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            allScore.push_back(GetScore(line));
            topPseudo.push_back(GetPseudo(line));
        }
        file.close();
    }

    for (int j = 0; j < allScore.size(); j++)
    {
        if (GetHightestNumber(allScore) == allScore[j])
        {
            allScore.erase(allScore.begin() + j);
            topPseudo.erase(topPseudo.begin() + j);
            j = 0;
        }
    }
    return topPseudo;
}

int ScoreManager::GetHightestNumber(std::vector<int> tab)
{
    int higthestScore = 0;
    for (int number : tab)
        if (number > higthestScore)
            higthestScore = number;
    return higthestScore;
}

int ScoreManager::GetScore(std::string chain)
{
    std::string scoreString;
    int scoreInt;
    int indice2point;

    for (int i = 0; i < chain.size(); i++)
    {
        if (chain[i] == ':')
        {
            indice2point = i;
            break;
        }
    }

    for (int i = indice2point + 1; i < chain.size(); i++)
        scoreString += chain[i];

    scoreInt = std::stoi(scoreString);
    return scoreInt;
}

std::string ScoreManager::GetPseudo(std::string chain)
{
    std::string pseudo;

    for (int i = 0; i < chain.size(); i++)
    {
        if (chain[i] == ':')
            break;
        pseudo += chain[i];
    }
    return pseudo;
}

void ScoreManager::SavePseudoAndScore(std::string pseudo, int score)
{
    std::ofstream file("ressources/scores.txt", std::ios::app);
    file << pseudo << ":" << score << "\n";
    file.close();
}