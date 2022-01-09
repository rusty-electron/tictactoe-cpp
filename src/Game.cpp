#include <iostream>
#include <string>
#include "Game.h"
#include "AI.h"

void Game::init() {
    if (_gamecount > 0) {
        _gb = Board(_size);
        _p1 = getOpponent(_p1);
    } else {
        _p1 = rand() % 2 + 1;
    }
    _p2 = getOpponent(_p1);

    _current_player = X_VAL;

    std::cout << "Welcome to TicTacToe! Game: " << _gamecount << std::endl;
    std::cout << "P1 has been allotted " << _gb.getSymbol(_p1) << std::endl;
    if (!_multi) {
        _ai.init(_p2);
        std::cout << "AI has been allotted " << _gb.getSymbol(_p2) << std::endl;
    } else {
        std::cout << "P2 has been allotted " << _gb.getSymbol(_p2) << std::endl;
    } 
}

void Game::run() {
    int result;
    while (_gameState != GameState::EXIT){
        _gb.show();
        if (!_multi && _current_player == _p2){
            _ai.performMove(_gb);
        } else {
            player_move();
        }

        result = _gb.checkVictory();
        if (result != NO_VAL){
            endGame(result);
        } else {
            switch_player();
        }
    }
}

void Game::player_move() {
    int in_x, in_y;
    bool valid_move = false;

    do {
        std::cout << "Player - " << _gb.getSymbol(_current_player) << 
            ": Choose move coordinate (x, y): ";
        std::cin >> in_x >> in_y; // switching x and y to r, c format

        if (in_x < 0 || in_y < 0 || in_x >= _gb.getSize() || in_y >= _gb.getSize()){
            std::cout << "ERROR: x and y value must in [0, " << 
                _gb.getSize() - 1 <<"]" << std::endl;
        } else if (_gb.getVal(in_x, in_y) != NO_VAL) {
            std::cout << "ERROR: this spot is occupied!" << std::endl;
        } else {
            valid_move = true;
        }

    } while (!valid_move);

    _gb.setVal(in_x, in_y, _current_player);
}

void Game::switch_player() {
    _current_player = getOpponent(_current_player);
}

void Game::endGame(int type) {
    _gb.show();
    if (type == TIE_VAL) {
        std::cout << "The game was a Tie!" << std::endl;
    } else {
        if (_current_player == X_VAL) {
            std::cout << "X won!" << std::endl;
        } else {
            std::cout << "O won!" << std::endl;
        }
    }

    std::string again = "";
    std::cout << "Press any key to play another game, Z/z to exit: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, again);

    if (again == "z" || again == "Z") {
        _gameState = GameState::EXIT;
    } else {
        _gamecount += 1;
        init();
    } 
}