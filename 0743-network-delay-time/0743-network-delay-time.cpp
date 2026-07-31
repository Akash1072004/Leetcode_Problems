class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>> graph[n];

        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0]-1].push_back({times[i][2], times[i][1]-1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        vector<int> dist(n, 1e9);

        dist[k-1] = 0;

        pq.push({0, k-1});

        while(!pq.empty()) {
            int node = pq.top().second;
            int distance = pq.top().first;

            pq.pop();

            for(auto ele : graph[node]) {
                if(ele.first+distance < dist[ele.second]) {
                    dist[ele.second] = ele.first+distance;
                    pq.push({dist[ele.second], ele.second});
                }
            }
        }

        int maxDistance =  0;

        for(int i = 0; i < n; i++) {
            if(dist[i] == 1e9) return -1;
            maxDistance = max(maxDistance, dist[i]);
        }

        return maxDistance;

    }
};