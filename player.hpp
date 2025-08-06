#pragma once

#include <string>

/**
 * Player Class
 * 
 * This class represents a player in the Tic-Tac-Toe game.
 * It implements the Singleton pattern to ensure only one instance of each player exists.
 */
class Player {
    private:
        std::string m_name;                                                     // Player's name
        char m_symbol;                                                          // Player's symbol (X or O) 
        int m_score;                                                            // Player's score

        static Player* player1;                                           // Singleton instance for Player 1
        static Player* player2;                                           // Singleton instance for Player 2

        Player(const std::string& playerName, char playerSymbol) 
            : m_name(playerName), m_symbol(playerSymbol), m_score(0) {}         // Private constructor
        
        /**
         * Reset Player's Score
         * 
         * Resets the player's score to 0.
         */
        void resetScore() {
            m_score = 0;
        }
        
        /**
         * Reset Player's Names to default 'Player 1' or 'Player 2'
         */
        void resetName(bool isPlayer1) {
            m_name = (isPlayer1 ? "Player 1" : "Player 2");
        }

        /**
         * Reset Player's Symbol to default 'X' or 'O'
         */
        void resetSymbol(bool isPlayer1) {
            m_symbol = (isPlayer1 ? 'X' : 'O');
        }
    public:
        Player(const Player&) = delete;                                         // Prevent copy-construction
        Player& operator=(const Player&) = delete;                              // Prevent assignment

        /**
         * Get Singleton Instances for Player1
         * 
         * @return const Player* - Pointer to Player 1 instance
         */
        static const Player* getPlayer1() {
            if (!player1) {
                player1 = new Player("Player 1", 'X');
            }
            return player1;
        }
        /**
         * Get Singleton Instances for Player2
         * 
         * Uses default name "Player 2" and symbol 'O'
         * 
         * @return const Player* - Pointer to Player 2 instance
         */
        static const Player* getPlayer2() {
            if (!player2) {
                player2 = new Player("Player 2", 'O');
            }
            return player2;
        }

        /**
         * Get Singleton Instances for Player1 with custom name
         * 
         * @param name - Custom name for Player 1
         * @return const Player* - Pointer to Player 1 instance
         */
        static const Player* getPlayer1(const std::string& name) {
            if (!player1) {
                player1 = new Player(name, 'X');
            }
            return player1;
        }

        /**
         * Get Singleton Instances for Player2 with custom name
         * 
         * @param name - Custom name for Player 2
         * @return const Player* - Pointer to Player 2 instance
         */
        static const Player* getPlayer2(const std::string& name) {
            if (!player2) {
                player2 = new Player(name, 'O');
            }
            return player2;
        }

        /**
         * Get Singleton Instances for Player1 with custom name and symbol
         * 
         * @param name - Custom name for Player 1
         * @param symbol - Custom symbol for Player 1
         * @return const Player* - Pointer to Player 1 instance
         */
        static const Player* getPlayer1(const std::string& name, char symbol) {
            if (!player1) {
                player1 = new Player(name, symbol);
            }
            return player1;
        }
        /**
         * Get Singleton Instances for Player2 with custom name and symbol
         * 
         * @param name - Custom name for Player 2
         * @param symbol - Custom symbol for Player 2
         * @return const Player* - Pointer to Player 2 instance
         */
        static const Player* getPlayer2(const std::string& name, char symbol) {
            if (!player2) {
                player2 = new Player(name, symbol);
            }
            return player2;
        }

        /**
         * Delete Players
         * 
         * Deletes the existing player instances and sets them to nullptr.
         * This is useful for starting a new game or resetting the game state.
         */
        static void deletePlayers() {
            delete player1;
            player1 = nullptr;
            delete player2;
            player2 = nullptr;
        }

        /**
         * Reset Players
         * 
         * Resets both players' scores to their default values.
         */
        static void resetPlayers() {
            player1->resetScore();
            player2->resetScore();
        }

        /**
         * Get Player's Name
         * 
         * @return std::string - Player's name
         */
        std::string getName() const {
            return m_name;
        }

        /**
         * Get Player's Symbol
         * 
         * @return char - Player's symbol (X or O)
         */
        char getSymbol() const {
            return m_symbol;
        }

        /**
         * Get Player's Score
         * 
         * @return int - Player's score
         */
        int getScore() const {
            return m_score;
        }

        /**
         * Increment Player's Score
         * 
         * Increases the player's score by 1.
         */
        void incrementScore() {
            m_score++;
        }

        
};
        