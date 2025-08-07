#pragma once

#include "game_board.hpp"

void game_board::display() const
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << m_board[i][j];
            if (j < 2)
                std::cout << " | "; // Column separator
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "---------" << std::endl; // Row separator
    }
}

bool game_board::makeMove(int row, int col, char symbol)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || m_board[row][col] != ' ')
    {
        return false; // Invalid move
    }
    m_board[row][col] = symbol; // Place the symbol on the board
    m_moves++;
    return true; // Move was successful
}

bool game_board::gameOver() const
{
    // Check for a win or draw condition
    for (int i = 0; i < 3; ++i)
    {
        // Check rows and columns
        if ((m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2] && m_board[i][0] != ' ') ||
            (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i] && m_board[0][i] != ' '))
        {
            return true; // Win found
        }
    }
    // Check diagonals
    if ((m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[0][0] != ' ') ||
        (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[0][2] != ' '))
    {
        return true; // Win found
    }
    return (m_moves >= 9); // Draw if all moves are made without a win
}