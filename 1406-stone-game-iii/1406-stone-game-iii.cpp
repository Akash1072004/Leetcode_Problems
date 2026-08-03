class Solution {
public:
    int dp[50001][2];
    int f(vector<int>& stoneValue, int i, bool turn, int n) {
        if(i >= n) return 0;
        if(dp[i][turn] != -1) return dp[i][turn];
        int ans = 0;
        if(turn) {
            ans = -1e9;
            ans = max(ans, stoneValue[i]+f(stoneValue, i+1, false, n));
            if(i+1 < n) ans = max(ans, stoneValue[i]+stoneValue[i+1]+f(stoneValue, i+2, false, n));
            if(i+2 < n) ans = max(ans, stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]+f(stoneValue, i+3, false, n));
        }
        else {
            ans = 1e9;
            ans = min(ans, -stoneValue[i]+f(stoneValue, i+1, true, n));
            if(i+1 < n) ans = min(ans, -(stoneValue[i]+stoneValue[i+1])+f(stoneValue, i+2, true, n));
            if(i+2 < n) ans = min(ans, -(stoneValue[i]+stoneValue[i+1]+stoneValue[i+2])+f(stoneValue, i+3, true, n));
        }
        return dp[i][turn] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        memset(dp, -1, sizeof dp);
        int ans = f(stoneValue, 0, true, n);
        // cout << ans << " ";
        if(ans < 0) return "Bob";
        else if(ans > 0) return "Alice";
        else return "Tie";

    }
};