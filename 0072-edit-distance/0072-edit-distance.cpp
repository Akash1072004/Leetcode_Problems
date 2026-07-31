class Solution {
public:
    int dp[501][501];
    int f(string &s, string &t, int i, int j){
        if(i == s.size()) return t.size()-j;
        if(j == t.size()) return s.size()-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = f(s, t, i+1, j+1);
        else {
            return dp[i][j] = min({1+f(s, t, i, j+1), 1+f(s, t, i+1, j), 1+f(s, t, i+1, j+1)});
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return f(word1, word2, 0, 0);
    }
};