#pragma once

#include <iostream>
class game_board {
    private:
        char m_board[3][3];                     // 3x3 Tic-Tac-Toe board
        int m_moves;                            // Count of moves made

        static const game_board* gameBoard;     // Singleton instance for the game board
        
        /**
         * Private constructor to initialize the game board
         */
        game_board() {
            reset(); // Initialize the board to empty state
        }
    public:
        game_board(const game_board&) = delete; // Prevent copy-construction
        game_board& operator=(const game_board&) = delete; // Prevent assignment

        /**
         * Get Singleton Instance of the game board
         * 
         * @return const game_board* - Pointer to the game board instance
         */
        static const game_board* getInstance() {
            if (!gameBoard) {
                gameBoard = new game_board();
            }
            return gameBoard;
        }

        /**
         * Reset the game board to its initial state
         */
        void reset() {
            m_moves = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    m_board[i][j] = ' ';        // Reset all cells to empty
                }
            }
        }

        /**
         * Display the current state of the game board
         */
        void display() const;

        /**
         * Make a move on the game board
         * 
         * @param row - Row index (0-2)
         * @param col - Column index (0-2)
         * @param symbol - Player's symbol ('X' or 'O')
         * @return bool - True if the move was successful, else false
         */
        bool makeMove(int row, int col, char symbol);

        bool gameOver() const {
            // Check for a win or draw condition
            for (int i = 0; i < 3; ++i) {
                // Check rows and columns
                if ((m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2] && m_board[i][0] != ' ') ||
                    (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i] && m_board[0][i] != ' ')) {
                    return true; // Win found
                }
            }
            // Check diagonals
            if ((m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[0][0] != ' ') ||
                (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[0][2] != ' ')) {
                return true; // Win found
            }
            return (m_moves >= 9); // Draw if all moves are made without a win
        }
};