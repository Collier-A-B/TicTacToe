#include "score_board.hpp"
#include "player.hpp"
#include <iostream>

void score_board::displayScoreBoard() {
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