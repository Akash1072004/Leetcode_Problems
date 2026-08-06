class Solution {
public:
    #define ll long long 
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix (n, vector<int> (m));
        vector<vector<int>> suffix (n, vector<int> (m));
        ll p = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefix[i][j] = p;
                p = (p * grid[i][j]) % 12345;
            }
        }
        ll s = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                suffix[i][j] = s;
                s = (s * grid[i][j]) % 12345;
            }
        }
        vector<vector<int>> ans(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[i][j] = (prefix[i][j] * suffix[i][j]) % 12345;
            }
        }
        return ans;


    }
};