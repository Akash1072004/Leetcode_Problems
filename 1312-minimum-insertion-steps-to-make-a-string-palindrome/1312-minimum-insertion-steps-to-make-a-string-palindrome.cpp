class Solution {
public:
    int dp[501][501];
    int f(string &s, int i, int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 2+f(s, i+1, j-1);
        return dp[i][j] = max(f(s, i+1, j), f(s, i, j-1));
    }
    int minInsertions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        int ans = f(s, 0, n-1);
        return n - ans;


    }
};