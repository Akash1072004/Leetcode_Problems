class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int f(int i, int j, int k, vector<vector<int>>& grid) {
        if(i >= m || j >= n || k < 0) return -1e9;
        if(i == m - 1 && j == n - 1) {
            if(k >= (grid[i][j] != 0)) return grid[i][j];
            return -1e9;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int cost = (grid[i][j] != 0);
        if(k < cost) return -1e9;
        int right = f(i, j + 1, k - cost, grid);
        int down = f(i + 1, j, k - cost, grid);
        int ans = max(right, down);
        if(ans < 0) return dp[i][j][k] = -1e9;
        return dp[i][j][k] = ans + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int ans = f(0, 0, k, grid);
        if(ans < 0) return -1;
        return ans;


    }
};