class Solution {
public:
    int m, n;
    int dp[201][201];
    int f(vector<vector<int>>& matrix, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        if(i+1 < m && matrix[i+1][j] > matrix[i][j]) {
            ans = max(ans, 1+f(matrix, i+1, j));
        }
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            ans = max(ans, 1+f(matrix, i-1, j));
        }
        if(j+1 < n && matrix[i][j+1] > matrix[i][j]) {
            ans = max(ans, 1+f(matrix, i, j+1));
        }
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            ans = max(ans, 1+f(matrix, i, j-1));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size();
        n = matrix[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, f(matrix, i, j));
            }
        }

        return ans;

    }
};