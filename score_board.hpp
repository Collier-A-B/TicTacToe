#include <iostream>

#include "player.hpp"

class score_board {
    private:
        score_board() {} // Private constructor to prevent instantiation
    public:
        score_board(const score_board&) = delete; // Prevent copy-construction
        score_board& operator=(const score_board&) = delete; // Prevent assignment 

        static void displayScoreBoard() {
            int p1Score = Player::getPlayer1()->getScore();
            int p2Score = Player::getPlayer2()->getScore();

            std::string p1Name = Player::getPlayer1()->getName();
            std::string p2Name = Player::getPlayer2()->getName();
            std::cout << "**********************************************************" << std::endl;
            std::cout << "\t\tScore Board" << std::endl;
            std::cout << "\t" << p1Name << " Score: " << p1Score << std::endl;
            std::cout << "\t" << p2Name << " Score: " << p2Score << std::endl;
            std::cout << "**********************************************************" << std::endl;
        }
};