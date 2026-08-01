class Solution {
public:
    int maxProduct(int n,vector<int>&dp){
        if(n==2)return 1;
        if(n==3)return 2;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i<n;i++){
            dp[n] = max({dp[n],i*maxProduct(n-i,dp),i*(n-i)});
            // feel like 9 se jo max layega usme 1 add kro ya 8 se max layega usme 2 add kro and so on .... and then ye bhi check kro ki khi (10-1)*1 bhi khi max to nhi ho rha ya fir (10-2)*2 to khi max nhi ho rha...and so on....
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return maxProduct(n,dp);

    }
};