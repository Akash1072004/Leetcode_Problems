class Solution {
public:
    int dp[100001];
    int f(vector<int>& costs, int i, int n) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int j = 1; j <= 3; j++) {
            if(i+j <= n) {
                int cost = costs[i+j-1] + j* j + f(costs, i+j, n);
                ans = min(ans, cost);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        memset(dp, -1, sizeof dp);

        return f(costs, 0, n);


    }
};