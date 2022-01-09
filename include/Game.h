#pragma once

#include "Board.h"
#include "AI.h"
#include <stdlib.h>
#include <time.h>

enum class GameState { PLAYING, EXIT };

class Game {
    private:
    Board _gb;
    int _p1;
    int _p2;
    int _size;
    int _current_player;
    bool _multi;
    AI _ai;

    GameState _gameState; // store the current state of the game

    void player_move();

    int getOpponent(int player) const { return (player == X_VAL)? O_VAL:X_VAL; }

    void switch_player();
    void endGame(int type);
    void reset();

    public:
    static int _gamecount;

    Game(int size = 3, bool multi = false): _gb(3) {
        srand(time(NULL)); // rng seed
        _size = size;
        _multi = multi;
        init();
    }
    void init(); // I am putting some init steps in this function
    void run();
};