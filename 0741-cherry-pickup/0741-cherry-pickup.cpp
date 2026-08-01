#define ll long long
class Solution {
public:
    ll dp[55][55][55];
    ll f(vector<vector<int>>&v,int i,int j,int x,int y,int n,int m){
        if(i==n || j==m || x==n || y==m || v[i][j]==-1 || v[x][y]==-1)return LLONG_MIN/2;
        if(i==n-1 && j==m-1){
            if(v[i][j]==1)return 1;
            else return 0;
        }
        if(dp[i][j][x]!=-1)return dp[i][j][x];
        ll result = INT_MIN;
        result = max(result,f(v,i+1,j,x+1,y,n,m));
        result = max(result,f(v,i+1,j,x,y+1,n,m));
        result = max(result,f(v,i,j+1,x+1,y,n,m));
        result = max(result,f(v,i,j+1,x,y+1,n,m));
        if(v[i][j]==1)result++;
        if(v[x][y]==1)result++;
        if(i==x && j==y && v[i][j]==1)result--;
        return dp[i][j][x] = result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        memset(dp,-1,sizeof dp);
        return max(0LL,f(grid,0,0,0,0,n,m));


    }
};