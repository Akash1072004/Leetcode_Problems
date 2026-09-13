class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i = 0; i < n; i++) {
            vector<int> v(n);
            for(int j = 0; j < n; j++) {
                v[j] = grid[i][(j+rowShift[i])% n];
            }
            grid[i] = v;
        }

        for(int j = 0; j < n; j++) {
            vector<int> v(n);
            for(int i = 0; i < n; i++) {
                v[i] = grid[(i+colShift[j])% n][j];
            }
            for(int i = 0; i < n; i++) {
                grid[i][j] = v[i];
            }
        }
        return grid;
        
    }
};