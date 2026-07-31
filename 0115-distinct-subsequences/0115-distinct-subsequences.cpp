#define ll long long
class Solution {
public:
    int dp[1001][1001];
    int f(string &s, string &t, int i, int j){
        if(j == t.size()) return 1; // formed the string t
        if(i == s.size()) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]) ans += f(s, t, i+1, j+1);
        ans += f(s, t, i+1, j);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof dp);
        return f(s, t, 0, 0);


    }
};