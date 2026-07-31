class Solution {
public:
    int obs(vector<vector<int>>&v,int r,int d,int m,int n,vector<vector<int>>&dp){
        if(r>=m-1 && d>=n-1){
            if(v[r][d]==0)return 1;
            else return 0;
        }
        if(r>m-1 || d>n-1)return 0;
        if(v[r][d]==1)return 0;
        if(dp[r][d]!=-1)return dp[r][d];
        dp[r][d]=obs(v,r+1,d,m,n,dp)+obs(v,r,d+1,m,n,dp);
        return dp[r][d];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return obs(v,0,0,m,n,dp);


    }
};