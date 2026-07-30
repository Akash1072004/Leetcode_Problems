class Solution {
public:
    #define ll long long
    long long minCost(int m, int n, vector<vector<int>>& penalty) {

        priority_queue<pair<ll, pair<int,pair<int, int>>>, vector<pair<ll, pair<int, pair<int, int>>>>, greater<pair<ll, pair<int, pair<int, int>>>>> pq;
        vector<vector<vector<ll>>> cost(m, vector<vector<ll>>(n, vector<ll>(2, 1e18)));

        cost[0][0][1] = 1;
        pq.push({1, {1, {0, 0}}});

        int dr[] = {-1, +1, 0, 0, 0};
        int dc[] = {0, 0, -1, +1, 0};

        while(!pq.empty()) {
            auto it = pq.top();
            int i = it.second.second.first;
            int j = it.second.second.second;
            int action = it.second.first;
            int a = action & 1;
            ll curCost = it.first;

            pq.pop();
            if(curCost > cost[i][j][a]) continue;
            // if(i == m-1 && j == n-1) return cost[i][j];

            for(int d = 0; d < 5; d++) {
                int nr = i+dr[d];
                int nc = j+dc[d];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(action & 1) {
                    if(((nr == i+1 && nc == j) || (nr == i && nc == j+1))) {
                        ll newCost = curCost+((nr+1)*1LL*(nc+1));
                        int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                    }
                   if(nr == i && nc == j) {
                       ll newCost = curCost+penalty[nr][nc];
                       int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                   }
                   else {
                        ll newCost = curCost+(penalty[i][j]+((nr+1)*1LL*(nc+1)));
                        int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                   }
                }
                else {
                    if((nr == i-1 && nc == j) || (nr == i && nc == j-1)) {
                        ll newCost = curCost+((nr+1)*1LL*(nc+1));
                        int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                    }
                   else if(nr == i && nc == j) {
                       ll newCost = curCost+penalty[i][j];
                       int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                   }
                   else {
                        ll newCost = curCost+(penalty[i][j]+((nr+1)*1LL*(nc+1)));
                        int na = !a;
                        if(cost[nr][nc][na] > newCost) {
                            cost[nr][nc][na] = newCost;
                            pq.push({newCost, {action+1, {nr, nc}}});
                        }
                   }
                }
            }
            
        }

        return min(cost[m-1][n-1][0], cost[m-1][n-1][1]);
        
        
    }
};