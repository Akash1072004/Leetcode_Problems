class Solution {
public:
    #define ll long long
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {

        vector<pair<ll, ll>> graph[n];

        for(auto it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

        pq.push({0, {power, source}});

        vector<vector<ll>> v(n, vector<ll>(power+1, -1));
        ll a = 1e15,b = -1;
        while(!pq.empty()){
            ll t = pq.top().first;
            ll p = pq.top().second.first;
            ll u = pq.top().second.second;
            pq.pop();
            if(t > a)break;
            if(u == target) {
                a = t;
                b = max(b,p);
                continue;
            }
            if(v[u][p] != -1 && v[u][p] <= t) continue;
            v[u][p] = t;

            if(p >= cost[u]){
                for(auto it : graph[u]) {
                    ll a = it.first;
                    ll b = it.second;
                    pq.push({t+b, {p-(ll)cost[u], a}});
                }
            }
        }
        if(a == 1e15)a = -1;
        return {a, b};
        
    }
};