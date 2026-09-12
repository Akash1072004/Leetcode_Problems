class Solution {
public:
    int minDays(int n) {

        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int k = 1; k*(k+1)/2 <= i; k++) {
                int x = k* (k+1)/2;
                dp[i] = min(dp[i], dp[i-x]+ k+1);
            }
        }

        return dp[n]-1;
        
    }
};