class Solution {
public:
    int m, n;
    int dp[76][76][76][5];
    int f(vector<vector<int>>& grid, int k, int i, int j, int turn) {
        if(i >= m || j >= n || i < 0 || j < 0) return 1e9;
        if(k < 0) return 1e9;
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j][k][turn] != -1) return dp[i][j][k][turn];
        int ans = 1e9;

        if(turn == 0) {
            ans = min(ans, grid[i][j]+f(grid, k, i+1, j, 1)); // down
            ans = min(ans, grid[i][j]+f(grid, k, i, j+1, 2)); // right
        } 
        else if(turn == 1) {
            ans = min(ans, grid[i][j]+f(grid, k, i+1, j, 1)); // down
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j+1, 2)); // right
            ans = min(ans, grid[i][j]+f(grid, k-1, i-1, j, 3)); // up
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j-1, 4)); // left
        }
        else if(turn == 2) {
            ans = min(ans, grid[i][j]+f(grid, k-1, i+1, j, 1)); // down
            ans = min(ans, grid[i][j]+f(grid, k, i, j+1, 2)); // right
            ans = min(ans, grid[i][j]+f(grid, k-1, i-1, j, 3)); // up
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j-1, 4)); // left
        }
        else if(turn == 3) {
            ans = min(ans, grid[i][j]+f(grid, k-1, i+1, j, 1)); // down
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j+1, 2)); // right
            ans = min(ans, grid[i][j]+f(grid, k, i-1, j, 3)); // up
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j-1, 4)); // left
        }
        else if(turn == 4) {
            ans = min(ans, grid[i][j]+f(grid, k-1, i+1, j, 1)); // down
            ans = min(ans, grid[i][j]+f(grid, k-1, i, j+1, 2)); // right
            ans = min(ans, grid[i][j]+f(grid, k-1, i-1, j, 3)); // up
            ans = min(ans, grid[i][j]+f(grid, k, i, j-1, 4)); // left
        }
        return dp[i][j][k][turn] = ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans = f(grid, k, 0, 0, 0);
        return (ans == 1e9) ? -1 : ans;

    }
};