class Solution {
public:
    int dp[100001][2][2];
    int f(vector<int>& prices, int i, bool flag, int k){
        if(i == prices.size() or k == 2) return 0;
        if(dp[i][flag][k] != -1) return dp[i][flag][k];
        int ans = 0;
        if(!flag){
            ans = max(f(prices, i+1, true, k)-prices[i], f(prices, i+1, false, k));
        }
        if(flag){
            ans = max(f(prices, i+1, false, k+1)+prices[i], f(prices, i+1, true, k));
        }
        return dp[i][flag][k] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, false, 0);



    }
};