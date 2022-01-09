#pragma once

#include <vector>
#include <string>

const int TIE_VAL = -1;
const int NO_VAL = 0;
const int X_VAL = 1;
const int O_VAL = 2;

class Board {
    private:
    std::vector<int> _board;
    int _size;

    char _symbols[3] = { '-', 'X', 'O' };

    public:
    Board(int size);

    void clear();
    void show() const;
    int checkVictory() const;

    int getVal(int x, int y) const {
        return _board[y * _size + x];
    }
    
    void setVal(int x, int y, int val) {
        _board[y * _size + x] = val;
    }

    char getSymbol(int val) const { return _symbols[val]; }
    int getEmptyCount() const;
    int getSize() const;
};