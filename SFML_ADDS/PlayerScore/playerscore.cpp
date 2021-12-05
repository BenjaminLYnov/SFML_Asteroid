#include "playerscore.h"

int PlayerScore::finalScore = 0;

PlayerScore::PlayerScore(int destroyed) : m_destroyed(destroyed) {
    CalculateScore();
}

PlayerScore::~PlayerScore() {
}

// Calcule le score du joueur

void PlayerScore::CalculateScore() {
    int ScoreJoueur = 0;

    switch (m_destroyed) {
    case 1:
        ScoreJoueur += m_destroyed * (rand() % 2);
        break;
    case 2:
        ScoreJoueur += m_destroyed + (rand() % 2) + 1;
        break;
    case 3:
        ScoreJoueur += m_destroyed * (rand() % 2) + 1;
    }
    finalScore += ScoreJoueur * 50;
}
