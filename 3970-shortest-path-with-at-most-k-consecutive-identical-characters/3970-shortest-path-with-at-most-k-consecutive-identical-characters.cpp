class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<pair<int, int>> graph[n];

        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][2], edges[i][1]});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 1}});
        vector<vector<int>> dist(n, vector<int> (k+1, 1e9));
        dist[0][1] = 0;
        int ans = 1e9;
        while(!pq.empty()) {
            auto it = pq.top();
            int node = it.second.first;
            int wt = it.first;
            int count = it.second.second;
            pq.pop();
            
            char preChar = labels[node];
            if(wt > dist[node][count]) continue;
            for(auto ele : graph[node]) {
                int c = 0;
                if(preChar == labels[ele.second]) c = count+1;
                else c = 1;
                if(c > k) continue;
                if(ele.first + wt < dist[ele.second][c]) {
                    dist[ele.second][c] = wt+ele.first;
                    pq.push({wt+ele.first, {ele.second, c}});
                }
            }
        }

        for(int i = 0; i <= k; i++) {
            ans = min(ans, dist[n-1][i]);
        }

        if(ans == 1e9) return -1;
        else return ans;
        
    }
};