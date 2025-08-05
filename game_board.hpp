
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
};