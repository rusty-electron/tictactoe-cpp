#pragma once
#include "Board.h"

struct AIMove {
    AIMove() {};
    AIMove(int score): score(score) {};
    int x;
    int y;
    int score;
};

class AI {
    AIMove getBestMove(Board& board, int currentPlayer);
    int _aiPlayer;
    int _humanPlayer = (_aiPlayer == X_VAL)? O_VAL: X_VAL;

    public:
    void init(int playerSign) { _aiPlayer = playerSign; }
    void performMove(Board& board);
};