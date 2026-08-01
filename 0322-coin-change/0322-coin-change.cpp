class Solution {
public:
    long long helper(vector<int>&coins,int amount,vector<long long>&dp){
        if(amount<0)return -1;
        if(amount==0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        long long m = INT_MAX;
        for(int i=0;i<coins.size();i++){
            long long ans = helper(coins,amount-coins[i],dp);
            if(ans!=-1)m = min(m,1+ans);
        }
        dp[amount]=m;
        if(dp[amount]==INT_MAX)return -1;
        else return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<long long>dp(amount+1,-1);
        return (int)helper(coins,amount,dp);


    }
};