class Solution {
public:
    int n, m;
    int dp[101][101][1001];
    bool f(vector<vector<char>>& grid, int i, int j, int count) {
        if(i >= n || j >= m) return false;
        
        if(grid[i][j] == '(') count++;
        else {
            if(count == 0) return false;
            count--;
        }

        if(i == n-1 && j == m-1) {
            return (count == 0);
        }

        if(dp[i][j][count] != -1) return dp[i][j][count];

        bool ans = false;
        ans |= f(grid, i+1, j, count);
        ans |= f(grid, i, j+1, count);

        return dp[i][j][count] = ans;

    }

    bool hasValidPath(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
        memset(dp, -1, sizeof dp);
        
        return f(grid, 0, 0, 0);

    }
};