class Solution {
public:
    int dp[100001][2];
    bool f(int n, bool turn) {
        if(n == 0 && turn) return false;
        if(n == 0 && !turn) return true;
        if(dp[n][turn] != -1) return dp[n][turn];
        bool ans = false;
        if(turn) {
            ans = false;
            for(int i = 1; i*i <= n; i++) {
                ans |= f(n-(i*i), false);
            }
        }
        else {
            ans = true;
            for(int i = 1; i*i <= n; i++) {
                ans &= f(n-(i*i), true);
            }
        }

        return dp[n][turn] = ans;
    }
    bool winnerSquareGame(int n) {

        memset(dp, -1, sizeof dp);
        return f(n, true); 

    }
};