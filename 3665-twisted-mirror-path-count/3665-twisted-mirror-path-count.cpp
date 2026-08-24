class Solution {
public:
    int MOD = 1e9 + 7;
    int n, m;
    int dp[501][501][2];
    int f(vector<vector<int>>& grid, int i, int j, int dir) {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if(grid[i][j] == 0) {
            return dp[i][j][dir] = (f(grid, i, j+1, 0)+f(grid, i+1, j, 1)) % MOD;
        }
        if(dir == 0) return dp[i][j][dir] = f(grid, i+1, j, 1);
        return dp[i][j][dir] = f(grid, i, j+1, 0);
    }
    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(grid, 0, 0, 0);
        
    }
};