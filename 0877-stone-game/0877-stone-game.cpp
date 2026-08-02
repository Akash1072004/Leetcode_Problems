class Solution {
public:
    int dp[501][501][2];
    int f(vector<int>& piles, int i, int j, bool turn) {
        if(i > j) return 0;
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        int ans = 0;
        if(turn) {
            ans = max(ans, piles[i]+f(piles, i+1, j, false));
            ans = max(ans, piles[j]+f(piles, i, j-1, false));
        }
        else {
            ans = min(ans, -piles[i]+f(piles, i+1, j, true));
            ans = min(ans, -piles[j]+f(piles, i, j-1, true));
        }
        return dp[i][j][turn] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int ans = f(piles, 0, n-1, true);
        memset(dp, -1, sizeof dp);
        return (ans >= 0) ? true : false;

    }
};