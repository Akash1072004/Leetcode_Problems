class Solution {
public:
    int m, n;
    int dp[1001][1001];
    #define MOD 1000000007
    int f(vector<vector<int>>& grid, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        if(i+1 < m && grid[i+1][j] > grid[i][j]) {
            ans = (ans + f(grid, i+1, j)) % MOD;
        }
        if(i-1 >= 0 && grid[i-1][j] > grid[i][j]) {
            ans = (ans + f(grid, i-1, j)) % MOD;
        }
        if(j+1 < n && grid[i][j+1] > grid[i][j]) {
            ans = (ans + f(grid, i, j+1)) % MOD;
        }
        if(j-1 >= 0 && grid[i][j-1] > grid[i][j]) {
            ans = (ans + f(grid, i, j-1)) % MOD;
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + f(grid, i, j)) % MOD;
            }
        }

        return ans;

    }
};