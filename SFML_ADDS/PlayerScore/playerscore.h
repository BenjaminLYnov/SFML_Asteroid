#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <iostream>

class PlayerScore
{
public:
    PlayerScore(int destroyed);
    ~PlayerScore();
    void CalculateScore();
    static int finalScore;

protected:
    int m_destroyed;
};

#endif // PLAYERSCORE_H
