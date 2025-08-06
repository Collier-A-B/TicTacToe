#pragma once

#include "game_board.hpp"

void game_board::display() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m_board[i][j];
            if (j < 2) 
                std::cout << " | "; // Column separator
        }
        std::cout << std::endl;
        if (i < 2) 
            std::cout << "---------" << std::endl; // Row separator
    }
}

bool game_board::makeMove(int row, int col, char symbol) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || m_board[row][col] != ' ') {
        return false; // Invalid move
    }
    m_board[row][col] = symbol; // Place the symbol on the board
    m_moves++;
    return true; // Move was successful
}