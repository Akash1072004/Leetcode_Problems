class Solution {
public:
    vector<int> adj[50005];
    int tin[50005], tout[50005], timer;
    int par[50005][17], depth[50005];
    int bit[50005];
    int val[50005];

    void dfs(int u, int p) {
        tin[u] = ++timer;
        par[u][0] = p;

        for(int i = 1; i < 17; i++) {
            par[u][i] = par[par[u][i-1]][i-1];
        }

        for(int v : adj[u]) {
            if(v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void update(int i, int x) {
        while(i <= timer) {
            bit[i] ^= x;
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;

        while(i > 0) {
            res ^= bit[i];
            i -= i & -i;
        }

        return res;
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for(int i = 0; i < 17; i++) {
            if(diff & (1 << i)) {
                u = par[u][i];
            }
        }

        if(u == v) return u;

        for(int i = 16; i >= 0; i--) {
            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }

        return par[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        timer = 0;
        depth[0] = 0;
        dfs(0, 0);

        for(int i = 0; i < n; i++) {
            val[i] = 1 << (s[i] - 'a');
            update(tin[i], val[i]);
            update(tout[i] + 1, val[i]);
        }

        vector<bool> ans;

        for(string q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if(type == "update") {
                char c;
                ss >> c;

                int newVal = 1 << (c - 'a');
                int change = val[u] ^ newVal;

                update(tin[u], change);
                update(tout[u] + 1, change);

                val[u] = newVal;
            } 
            else {
                ss >> v;

                int w = lca(u, v);

                int mask = query(tin[u]) ^ query(tin[v]) ^ val[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};