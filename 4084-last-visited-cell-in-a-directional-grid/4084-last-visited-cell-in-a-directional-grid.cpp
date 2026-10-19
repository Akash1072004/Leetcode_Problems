class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int row = 0, col = 0;
        vis[row][col] = 1;

        while(true) {
            int newRow = row, newCol = col;
            if(grid[row][col] == 'L') newCol--;
            else if(grid[row][col] == 'R') newCol++;
            else if(grid[row][col] == 'U') newRow--;
            else if(grid[row][col] == 'D') newRow++;

            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || vis[newRow][newCol]) {
                break;
            }

            row = newRow;
            col = newCol;
            vis[row][col] = 1;
        }

        return {row, col};


    }
};