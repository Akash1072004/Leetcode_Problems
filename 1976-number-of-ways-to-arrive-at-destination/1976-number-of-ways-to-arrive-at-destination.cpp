class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<ll, ll>> graph[n];

        for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            graph[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;

        pq.push({0, 0});

        vector<pair<ll, ll> > dist(n, {1e18, 1});

        dist[0] = {0, 1}; // {distance, number of path}

        while(!pq.empty()) {
            ll node = pq.top().second;
            ll distance = pq.top().first;

            pq.pop();

            for(auto ele : graph[node]) {
                if(ele.first+distance == dist[ele.second].first) {
                    dist[ele.second].second = (dist[ele.second].second % MOD + dist[node].second % MOD) % MOD;
                }
                else if(ele.first+distance < dist[ele.second].first) {
                    dist[ele.second].first = ele.first+distance;
                    dist[ele.second].second = dist[node].second;
                    pq.push({dist[ele.second].first, ele.second});
                }
            }
        }
        
        return dist[n-1].second % MOD;

    }
};