class Solution {
public:
    #define ll long long
    #define mod 1000000007
    vector<bool> vis;
    vector<int> dist, tin, tout;
    vector<int> parent;
    int x = 0;
    ll power(ll a, ll b) {
        if(b < 0)return 0;
        ll res = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }
    void Depth(vector<int> graph[], int node, int d) {
        vis[node] = true;
        dist[node] = d;
        tin[node] = x++;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                Depth(graph, it, d+1);
                vis[it] = true;
            }
        }
        tout[node] = x++;
    }
    void findParent(vector<int> graph[], int node, int p) {
        vis[node] = true;
        parent[node] = p;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                findParent(graph, it, node);
                vis[it] = true;
            }
        }
    }
    int lca(int u, int v) {
        if(dist[u] < dist[v]) {
            int p = u;
            while(p != -1) {
                if(tin[p] <= tin[v] && tout[p] >= tout[v]) return p;
                p = parent[p]; 
            }
        }
        else {
            int p = v;
            while(p != -1) {
                if(tin[p] <= tin[u] && tout[p] >= tout[u]) return p;
                p = parent[p]; 
            }
        }
        return 1;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {

        int n = edges.size();
        
        vector<int> graph[n+1];
        for(int i = 0; i < n; i++) {
            graph[edges[i][0]-1].push_back(edges[i][1]-1);
            graph[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        vis.resize(n+1, false);
        dist.resize(n+1, 0);
        tin.resize(n+1, 0);
        tout.resize(n+1, 0);
        Depth(graph, 0, 0);

        vector<int> ans;
        for(int i = 0; i < n+1; i++) {
            vis[i] = false;
        }

        parent.resize(n+1, -1);
        findParent(graph, 0, -1);

        for(int i = 0; i < queries.size(); i++) {
            int u = queries[i][0]-1;
            int v = queries[i][1]-1;
            int a = lca(u, v);
            int b = dist[u]+dist[v] - (2*dist[a]);
            int d = power(2, b-1);
            ans.push_back(d);
        }

        return ans;

    }
};