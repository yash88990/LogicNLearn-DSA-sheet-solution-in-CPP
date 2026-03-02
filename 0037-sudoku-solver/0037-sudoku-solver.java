class Solution {

    public boolean isSafe(int row, int col, char[][] board, char val) {

        for (int i = 0; i < 9; i++) {

            //check row
            if (board[row][i] == val) return false;

            //check column
            if (board[i][col] == val) return false;

            //check 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == val) return false;
        }

        return true;
    }

    public boolean solve(char[][] board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                //find empty cell
                if (board[row][col] == '.') {

                    //try digits 1 to 9
                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isSafe(row, col, board, ch)) {
                            board[row][col] = ch;

                            //recursive solve
                            if (solve(board)) return true;

                            //backtrack
                            board[row][col] = '.';
                        }
                    }

                    return false; //no valid number found
                }
            }
        }

        return true; //board solved
    }

    public void solveSudoku(char[][] board) {
        solve(board);
    }
}