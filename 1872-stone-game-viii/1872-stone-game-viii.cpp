class Solution {
public:
    int dp[100001][2];
    int f(vector<int>& stones, vector<int>& pre, int i, int turn) {
        if(i == stones.size()-1) {
            if(turn) return pre[i];
            else return -pre[i];
        }
        if(dp[i][turn] != -1) return dp[i][turn];
        int ans = 0;
        if(turn) {
            ans = -1e9;
            ans = max(ans, f(stones, pre, i+1, true));
            ans = max(ans, pre[i]+f(stones, pre, i+1, false));
        }
        else {
            ans = 1e9;
            ans = min(ans, f(stones, pre, i+1, false));
            ans = min(ans, -pre[i]+f(stones, pre, i+1, true));
        }

        return dp[i][turn] = ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        
        int n = stones.size();
        vector<int> pre(n, 0);
        pre[0] = stones[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1]+stones[i];
        }
        
        memset(dp, -1, sizeof dp);
        
        return f(stones, pre, 1, true);

    }
};