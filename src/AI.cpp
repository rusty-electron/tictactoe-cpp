#include "AI.h"
#include <vector>

AIMove AI::getBestMove(Board& board, int currentPlayer) {
    int res = board.checkVictory();
    if (res == _aiPlayer){
        return AIMove(10 + board.getEmptyCount());
    } else if (res == _humanPlayer) {
        return AIMove(-10 - board.getEmptyCount());
    } else if (res == TIE_VAL) {
        return AIMove(0);
    }

    std::vector<AIMove> moves;

    for (int i=0; i<board.getSize(); i++) {
        for (int j=0; j<board.getSize(); j++) {
            if (board.getVal(i, j) == NO_VAL) {
                AIMove currentMove;
                currentMove.x = i;
                currentMove.y = j;

                board.setVal(i, j, currentPlayer);
                currentMove.score = getBestMove(board, currentPlayer == _aiPlayer?_humanPlayer:_aiPlayer).score;
                board.setVal(i, j, NO_VAL);

                moves.push_back(currentMove);
            }
        }
    }

    int bestMoveIndex = 0;
    if (currentPlayer == _aiPlayer){
        int bestScore = -10000;
        for (int i=0; i<moves.size(); i++){
            if (moves[i].score > bestScore){
                bestMoveIndex = i;
                bestScore = moves[i].score;
            }
        }
    } else {
        int bestScore = 10000;
        for (int i=0; i<moves.size(); i++){
            if (moves[i].score < bestScore){
                bestMoveIndex = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMoveIndex];
}

void AI::performMove(Board& board){
    AIMove chosenMove = getBestMove(board, _aiPlayer);
    board.setVal(chosenMove.x, chosenMove.y, _aiPlayer);
    printf("AI made the move: (%d, %d)\n", chosenMove.x, chosenMove.y);
}