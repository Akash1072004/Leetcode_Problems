class Solution {
public:
    // int dp[2001][2001];
    // bool f(string &s, string &p, int i, int j){
    //     if(i == s.size() and j == p.size()) return true;
    //     if(i == s.size() and j < p.size()){
    //         for(int k = j; k < p.size(); k++){
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(p[j] == s[i] or p[j] == '?') return dp[i][j] = f(s, p, i+1, j+1);
    //     else if(p[j] == '*'){
    //         return dp[i][j] = f(s, p, i+1, j) or f(s, p, i, j+1);
    //     }
    //     else return false;
    // }
    bool isMatch(string s, string p) {
        // memset(dp, -1, sizeof dp);
        // return f(s, p, 0, 0);
        int n = s.size(); int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[n][m] = true;
        for(int j = m-1; j >= 0; j--){
            if(p[j] == '*') dp[n][j] = dp[n][j+1];
            else dp[n][j] = false;
        }
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = p.size()-1; j >= 0; j--){
                if(p[j] == s[i] or p[j] == '?') dp[i][j] = dp[i+1][j+1];
                else if(p[j] == '*'){
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[0][0];


    }
};