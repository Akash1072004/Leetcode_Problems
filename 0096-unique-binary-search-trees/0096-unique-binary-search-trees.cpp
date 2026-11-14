class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n==0 || n==1)return 1;
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];
        int sum = 0;
        for(int k=1;k<=n;k++){
           dp[n] = sum += (helper(k-1,dp)*helper(n-k,dp));
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);


    }
};