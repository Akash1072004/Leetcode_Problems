class Solution {
public:
    int dp[101][2][101];
    int f(vector<int>& piles, int i, bool turn, int m, vector<int>& pre, int n) {
        if(i >= piles.size()) return 0;
        if(dp[i][turn][m] != -1) return dp[i][turn][m];
        int ans = 0;
        int x = 2* m;
        if(turn) {
            ans = -1e9;
            int a = 0;
            for(int j = i; j < min(i+x, n); j++) {
                if(i-1 >= 0) a = pre[j]-pre[i-1];
                else a = pre[j];
                ans = max(ans, a+f(piles, j+1, false, max(m, j-i+1), pre, n));
            }
        }
        else {
            ans = 1e9;
            int a = 0;
            for(int j = i; j < min(i+x, n); j++) {
                if(i-1 >= 0) a = pre[j]-pre[i-1];
                else a = pre[j];
                ans = min(ans, -a+f(piles, j+1, true, max(m, j-i+1), pre, n));
            }
        }

        return dp[i][turn][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<int> pre(n, 0);
        pre[0] = piles[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1]+piles[i];
        }
        memset(dp, -1, sizeof dp);
        int diff = f(piles, 0, true, 1, pre, n);

        int AliceScore = (pre.back()+diff)/2;

        return AliceScore;

    }
};