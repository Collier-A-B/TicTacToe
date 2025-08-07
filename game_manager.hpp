#pragma once

#include "player.hpp"
#include "game_board.hpp"
#include "score_board.hpp"

class game_manager {
    private:
        bool m_playyerOneTurn;                   // boolean flag to track the current player: true for Player 1, false for Player 2
        /**
         * constructor for game_manager
         * 
         * Sets Player 1 as the current player.
         */
        
        const game_board* m_gameBoard;
        const Player* m_playerOne;
        const Player* m_playerTwo;

        static game_manager* instance; // Singleton instance of game_manager

        game_manager() :  m_playyerOneTurn(true) {
            m_gameBoard = game_board::getInstance(); // Get the singleton instance of game_board
            m_playerOne = Player::getPlayer1(); // Get the singleton instance of Player 1
            m_playerTwo = Player::getPlayer2(); // Get the singleton instance of Player 2
        }
    public:
        game_manager(const game_manager&) = delete; // Prevent copy-construction
        game_manager& operator=(const game_manager&) = delete; // Prevent assignment

        /**
         * Get Singleton Instance of the game manager
         * 
         * @return game_manager* - Pointer to the game manager instance
         */
        static game_manager* getInstance() {
            if (!instance) {
                instance = new game_manager();
            }
            return instance;
        }

        /**
         * Start a new game
         */
        void startGame();

        /**
         * Reset the game state
         */
        void resetGame();

        /**
         * Make a move on the board
         * 
         * @param row - Row index (0-2)
         * @param col - Column index (0-2)
         */
        void makeMove(int row, int col);

        /**
         * Display the current state of the game board
         */
        void displayBoard() const;

        /**
         * Display the score board
         */
        void displayScoreBoard() const;

        /**
         * Check if the game is over
         * 
         * @return bool - True if the game is over, else false
         */
        bool isGameOver() const;
        
};