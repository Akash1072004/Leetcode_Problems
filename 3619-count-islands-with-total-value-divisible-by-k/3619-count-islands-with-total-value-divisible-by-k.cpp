class Solution {
public:
    #define ll long long
    int m, n;
    ll dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(grid[i][j] == 0 || vis[i][j]) return 0;
        vis[i][j] = 1;
    
        ll ans = grid[i][j];
        ans += dfs(grid, vis, i+1, j);
        ans += dfs(grid, vis, i-1, j);
        ans += dfs(grid, vis, i, j+1);
        ans += dfs(grid, vis, i, j-1);
        return ans;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    ll sum = dfs(grid, vis, i, j);
                    if(sum % k == 0) ans++;
                }
            }
        }
        
        return ans;


    }
};