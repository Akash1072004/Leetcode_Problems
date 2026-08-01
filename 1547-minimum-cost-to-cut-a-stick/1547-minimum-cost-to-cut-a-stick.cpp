class Solution {
public:
    int dp[110][110];
    int f(vector<int>& cuts, int i, int j){
        if(i + 1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        // Partition the DP
        for(int k = i+1; k < j; k++){
            ans = min(ans, (cuts[j]-cuts[i])+f(cuts, i, k)+f(cuts, k, j));
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof dp);
        return f(cuts, 0, cuts.size()-1);
    }
};