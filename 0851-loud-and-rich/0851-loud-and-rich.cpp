class Solution {
public:
    int dfs(int node, vector<int> adj[], vector<int>& quiet, vector<int>& ans) {
        if(ans[node] != -1) return ans[node];

        ans[node] = node;

        for(auto it : adj[node]) {
            int temp = dfs(it, adj, quiet, ans);

            if (quiet[temp] < quiet[ans[node]]) {
                ans[node] = temp;
            }
        }

        return ans[node];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<int> adj[n];

        for(auto it : richer) {
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            dfs(i, adj, quiet, ans);
        }

        return ans;

    }
};
