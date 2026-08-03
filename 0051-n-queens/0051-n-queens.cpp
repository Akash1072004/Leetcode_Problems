class Solution {
public:
    bool isSafe(int i, int col, vector<vector<int>>&v, int n){
        for(int a = i, b = col; a >= 0 and b < n; a--, b++){
            if(v[a][b] == 0)return false;
        }
        for(int a = i, b = col; a >= 0 and b >= 0; a--, b--){
            if(v[a][b] == 0)return false;
        }
        return true;
    }
    void f(int n, vector<vector<string>>&ans, int i, int mask, vector<vector<int>>&v,vector<string>&temp) {
        if(i == n) {
            if(mask == 0){
                ans.push_back(temp);
            }
            return;
        }
        for(int col = 0; col < n; col++){
            if(((1 << col) & mask) and isSafe(i,col,v,n)){
                mask = mask ^ (1 << col);
                v[i][col] = 0;
                temp[i][col] = 'Q';
                f(n,ans,i+1,mask,v,temp);
                temp[i][col] = '.';
                mask = (mask | (1 << col));
                v[i][col] = 1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>v(n,vector<int>(n,1));
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        f(n,ans,0,(1 << n) - 1,v,temp);
        return ans;



    }
};