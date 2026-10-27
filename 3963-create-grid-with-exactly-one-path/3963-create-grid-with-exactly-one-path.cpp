class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        for(int i = 0; i < m; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == n-1) s += '.';
                else s += '#';
            }
            grid[i] = s;
        }

        return grid;
    }
};