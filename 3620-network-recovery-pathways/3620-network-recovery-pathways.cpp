class Solution {
public:
    #define ll long long
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        ll n = online.size();

        vector<pair<ll, ll>> graph[n];

        for(ll i = 0; i < (ll)edges.size(); i++) {
            graph[edges[i][0]].push_back({(ll)edges[i][2], (ll)edges[i][1]});
        }

        ll low = 0, high = 1e18;

        ll ans = -1;

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

            pq.push({0, 0});

            vector<ll> minCost(n, 1e18);
            minCost[0] = 0;

            while(!pq.empty()) {
                auto it = pq.top();
                pq.pop();

                ll node = it.second;
                ll curCost = it.first;
                if(curCost > minCost[node]) continue;
                for(auto &u : graph[node]) {
                    if (u.first < mid || !online[u.second]) continue;

                    if (minCost[u.second] > curCost + u.first) {
                        minCost[u.second] = curCost + u.first;

                        pq.push({minCost[u.second], u.second});
                    }
                }
            }

            if(minCost[n-1] > k) {
                high = mid-1;
            } else {
                ans = mid;
                low = mid+1;
            }
        }

        return (int)ans;
    }
};