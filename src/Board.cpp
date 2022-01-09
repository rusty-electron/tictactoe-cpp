#include <string>
#include "Board.h"

Board::Board(int size = 3){
    _size = size;
    _board.resize(size*size);
    clear();
}

void Board::clear() {
    for (size_t i = 0; i < _board.size(); i++){
        _board[i] = NO_VAL;
    }
}

void Board::show() const {
    printf("\n");
    printf("  0 1 2\n");
    for (size_t i = 0; i < _board.size(); i++){
        if (i % _size == 0){
            printf("%d ", (int)i/_size);
        }

        printf("%c ", _symbols[_board[i]]);

        if ((i+1) % _size == 0){
            printf("\n");
        }
    }
    printf("\n");
}

int Board::checkVictory() const {
    bool victory;
    int c;

    // check the rows
    for(int y=0; y<_size; y++){
        c = getVal(0, y);
        if (c != NO_VAL){
            victory = true;
            for(int x=0; x<_size; x++){
                if (getVal(x, y) != c){
                    victory = false;
                    break;
                }
            }
            if (victory) { return c; }
        }
    }

    // check the columns
    for(int x=0; x<_size; x++){
        c = getVal(x, 0);
        if (c != NO_VAL){
            victory = true;
            for(int y=0; y<_size; y++){
                if (getVal(x, y) != c){
                    victory = false;
                    break;
                }
            }
            if (victory) { return c; }
        }
    }

    // check first diagonal
    c = getVal(0, 0);
    if (c != NO_VAL){
        victory = true;
        for (int i=1; i<_size; i++){
            if (getVal(i, i) != c) {
                victory = false;
                break;
            }
        }
        if (victory) { return c; }
    }

    // check second diagonal
    c = getVal(0, _size - 1);
    if (c != NO_VAL){
        victory = true;
        for (int i=1; i<_size; i++){
            if (getVal(i, _size - i - 1) != c) {
                victory = false;
                break;
            }
        }
        if (victory) { return c; }
    }

    // check if empty spaces exist
    for (size_t i=0; i<_board.size(); i++){
        if (_board[i] == NO_VAL) return NO_VAL;
    }

    return TIE_VAL;
}

int Board::getSize() const {
    return _size;
}

int Board::getEmptyCount() const {
    int count = 0;
    for (size_t i=0; i<_board.size(); i++){
        if (_board[i] == NO_VAL) { count++; }
    }
    return count;
}