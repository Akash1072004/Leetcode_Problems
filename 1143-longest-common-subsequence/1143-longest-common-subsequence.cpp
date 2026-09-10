class Solution {
public:
    int dp[1001][1001];
    int f(string &s, string &t, int i, int j){
        if(i == s.size() || j == t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1+f(s,t, i+1, j+1);
        return dp[i][j] = max(f(s, t, i+1, j), f(s, t, i, j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return f(text1, text2, 0, 0);



    }

};