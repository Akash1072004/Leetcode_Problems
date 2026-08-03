class Solution {
public:
    vector<vector<int>>v;
    int count = 0;
    bool isSafe(int i, int j, int n){
        for(int k = i; k >= 0; k--){
            if(v[k][j] == 1)return false;
        }
        for(int k = i, l = j; k >= 0 and l >= 0; k--, l--){
            if(v[k][l] == 1)return false;
        }
        for(int k = i, l = j; k >= 0 and l < n; k--, l++){
            if(v[k][l] == 1)return false;
        }
        return true;
    }
    void f(int n, int i, int mask){
        if(i == n){
            if(mask == 0) count++;
            return;
        }
        for(int col = 0; col < n; col++){
            if((mask & (1<<col)) and isSafe(i,col,n)){
                mask = (mask ^ (1<<col));
                v[i][col] = 1;
                f(n,i+1,mask);
                mask = (mask | (1<<col));
                v[i][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        v.resize(n, vector<int>(n,0));
        f(n,0,((1<<n) - 1));
        return count;


    }
};