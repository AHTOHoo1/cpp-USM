#include <array>
#include <cstddef>
#include <iostream>

struct ScoreBoard
{
    std::array<int, 5> totalScores;
};

int getRoundScore(ScoreBoard board, size_t roundIndex)
{
    return board.totalScores[roundIndex] -
        board.totalScores[roundIndex - 1];
}

void correctScore(
    ScoreBoard* board,
    size_t roundIndex,
    int correctedTotal)
{
    board->totalScores[roundIndex] = correctedTotal;
}

int main()
{
    ScoreBoard board{
        .totalScores{ 10, 25, 40, 60, 85 }
    };

    std::cout << getRoundScore(board, 2) << std::endl;

    correctScore(&board, 3, 65);

    std::cout << getRoundScore(board, 3) << std::endl;
}