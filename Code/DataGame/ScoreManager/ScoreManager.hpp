#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#pragma once

#include <vector>
#include <string>

class ScoreManager
{
public:
	static int GetHightestScore();
	static std::vector<int> GetTopScore(int topNumber);
	static std::vector<std::string> GetTopPseudo(int topNumber);
	static void SavePseudoAndScore(std::string pseudo, int score);

private:
	static int GetHightestNumber(std::vector<int> tab);

	// chain must be like this form : "pseudo:13"
	static int GetScore(std::string chain);
	static std::string GetPseudo(std::string chain);
};
#endif