class Solution {
public:
    #define ll long long
    ll dp[1005][505][3];
    ll f(int i, int k, int state, vector<int>& prices) {
        if(i == prices.size()) {
            if(state == 0) return 0;
            return -1e18;
        }
        if(dp[i][k][state] != -1) return dp[i][k][state];
        ll ans = f(i+1, k, state, prices);
        if(state == 0 && k > 0) {
            ans = max(ans, -1LL* prices[i] + f(i+1, k, 1, prices));
            ans = max(ans, 1LL* prices[i] + f(i+1, k, 2, prices));
        } 
        else if(state == 1 && k > 0) {
            ans = max(ans, 1LL* prices[i] + f(i+1, k-1, 0, prices));
        } 
        else if(state == 2 && k > 0) {
            ans = max(ans, -1LL* prices[i] + f(i+1, k-1, 0, prices));
        }
        return dp[i][k][state] = ans;

    }

    long long maximumProfit(vector<int>& prices, int k) {

        memset(dp, -1, sizeof(dp));
        return f(0, k, 0, prices);

    }
};