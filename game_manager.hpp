
#include "player.hpp"

class game_manager {
    private:
        const Player* m_currentPlayer;                              

    public:
        game_manager() : m_currentPlayer(nullptr) {}               // Constructor initializes current player to nullptr

        /**
         * Start the Game
         * 
         * Initializes the game and sets the starting player.
         */
        void startGame() {
            m_currentPlayer = Player::getPlayer1();                 // Set Player 1 as the starting player
            // Additional game initialization logic can be added here
        }

        /**
         * Switch Turns
         * 
         * Switches the turn to the other player.
         */
        void switchTurn() {
            if (m_currentPlayer == Player::getPlayer1()) {
                m_currentPlayer = Player::getPlayer2();
            } else {
                m_currentPlayer = Player::getPlayer1();
            }
        }

        /**
         * Get Current Player
         * 
         * @return const Player* - Pointer to the current player
         */
        const Player* getCurrentPlayer() const {
            return m_currentPlayer;
        }

        // Additional game management methods can be added here
};