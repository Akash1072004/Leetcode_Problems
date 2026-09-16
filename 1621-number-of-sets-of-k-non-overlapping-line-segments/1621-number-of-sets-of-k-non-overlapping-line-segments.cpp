class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int dp[1001][1001][2];
    int f(int n, int k, int i, int take) {
        if(k == 0) return 1;
        if(i >= n) return 0;
        if(dp[i][k][take] != -1) return dp[i][k][take];
        ll ans = 0;
        if(take == 0) { // outside the segment
            ans += f(n, k, i+1, 0); // we will not start from here, we will move ahead take = 0
            ans += f(n, k, i+1, 1); // now starting point is i and take = 1
        } 
        else { // inside the segment 
            ans += f(n, k, i+1, 1); // increase the segment length
            ans += f(n, k-1, i, 0); // now stops at point i and take this segment and then start from this i again 
        }
        return dp[i][k][take] = ans % MOD;
    }

    int numberOfSets(int n, int k) {

        memset(dp, -1, sizeof(dp));

        return f(n, k, 0, 0);

    }
};