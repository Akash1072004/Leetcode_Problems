class Solution {
public:
    vector<int> ans;
    vector<int> adj[100005], newAdj[100005];
    int last[26];
    void dfs1(int u, vector<int>& par, string &s) {
        int c = s[u] - 'a';

        int prev = last[c];

        if(prev != -1) {
            par[u] = prev;
        }

        last[c] = u;

        for(auto v : adj[u]) {
            dfs1(v, par, s);
        }

        last[c] = prev;
    }

    int dfs2(int u) {
        int sz = 1;
        for(auto v : newAdj[u]) {
            sz += dfs2(v);
        }

        ans[u] = sz;

        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        ans.resize(n);

        for(int i = 0; i < n; i++) {
            adj[i].clear();
            newAdj[i].clear();
        }

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        for(int i = 0; i < 26; i++) {
            last[i] = -1;
        }

        dfs1(0, parent, s);

        for(int i = 1; i < n; i++) {
            newAdj[parent[i]].push_back(i);
        }

        dfs2(0);

        return ans;


    }
};