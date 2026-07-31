class Solution {
public:
    #define pp pair<int, pair<int, int> > 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int> > graph[n];

        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][2], flights[i][1]});
        }

        queue<pp> q;

        vector<int> dist(n, 1e9);

        dist[src] = 0;

        q.push({0, {src, k}});

        while(!q.empty()) {
            auto it = q.front();
            int node = it.second.first;
            int limit = it.second.second;
            int distance = it.first;

            q.pop();

            // if(k == -1 && node == dst) return dist[node];
            if(limit == -1) continue;

            for(auto ele : graph[node]) {
                if(dist[ele.second] > ele.first+distance && limit >= 0) {
                    dist[ele.second] = ele.first+distance;

                    q.push({dist[ele.second], {ele.second, limit-1}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        else return dist[dst];

    }
};