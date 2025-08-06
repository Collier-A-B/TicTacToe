#pragma once

#include <iostream>

#include "player.hpp"

class score_board {
    private:
        score_board() {} // Private constructor to prevent instantiation
    public:
        score_board(const score_board&) = delete; // Prevent copy-construction
        score_board& operator=(const score_board&) = delete; // Prevent assignment 

        static void displayScoreBoard();
};