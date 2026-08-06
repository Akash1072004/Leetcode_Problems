class Solution {
public:
    int dp[505][505];
    int f(int l, int r, vector<int>& pre) {
        if (l == r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for(int k = l; k < r; k++) {
            int left = pre[k] - (l == 0 ? 0 : pre[l-1]);
            int right = pre[r] - pre[k];
            if(left < right) {
                ans = max(ans, left+f(l, k, pre));
            }
            else if(left > right) {
                ans = max(ans, right+f(k+1, r, pre));
            }
            else {
                ans = max(ans, left+max(f(l, k, pre), f(k+1, r, pre)));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> pre(n, 0);
        pre[0] = stoneValue[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + stoneValue[i];
        }

        memset(dp, -1, sizeof(dp));
        return f(0, n-1, pre);


    }
};