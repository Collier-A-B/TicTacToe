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
        game_manager() :  m_playyerOneTurn(true) {} // Initialize with Player 1 as current player
    public:
        
};