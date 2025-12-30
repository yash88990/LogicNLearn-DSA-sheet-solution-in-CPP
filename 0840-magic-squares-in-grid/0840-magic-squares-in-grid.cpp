class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Check if all numbers are distinct and within 1 to 9
        vector<int> count(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[r+i][c+j];
                if (num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }
        
        // Check the sum of rows, columns, and diagonals
        int s = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        
        for (int i = 0; i < 3; ++i) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != s) return false;
            if (grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != s) return false;
        }
        
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != s) return false;
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != s) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for (int r = 0; r < rows - 2; ++r) {
            for (int c = 0; c < cols - 2; ++c) {
                if (grid[r+1][c+1] == 5 && isMagic(grid, r, c)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};