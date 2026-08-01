class Solution {
public:
    int maxMoney(vector<int>&v,int n,int i,vector<int>&dp){
        if(i>n)return 0;
        if(i==n)return v[i];
        if(dp[i]!=-1)return dp[i];
        dp[i] = max(maxMoney(v,n,i+1,dp),v[i]+maxMoney(v,n,i+2,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxMoney(nums,n-1,0,dp);


    }
};