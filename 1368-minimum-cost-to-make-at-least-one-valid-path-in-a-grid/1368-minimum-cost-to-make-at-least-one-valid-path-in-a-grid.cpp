class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<vector<int>>dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        while(!dq.empty()){
            auto cur = dq.front();
            int x = cur.first;
            int y = cur.second;
            dq.pop_front();
            if(vis[x][y])continue;
            vis[x][y] = true;
            for(int i = 0; i < 4; i++){
                int newRow = x + dx[i];
                int newCol = y + dy[i];
                if(newRow < 0 or newCol < 0 or newRow >=m or newCol >=n) continue;
                if(dist[newRow][newCol] > dist[x][y] + ((grid[x][y] == i+1) ? 0 : 1)) { // check directions
                    dist[newRow][newCol] = dist[x][y] + ((grid[x][y] == i+1) ? 0 : 1);
                    if(grid[x][y] == i+1) dq.push_front({newRow, newCol});
                    else dq.push_back({newRow, newCol});
                }
            }
        }
        return dist[m-1][n-1];


    }
};