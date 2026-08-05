class Solution {
public:
    vector<int> vis;
    void dfs(vector<int> graph[], int i, vector<int>& suspicious) {
        if(vis[i]) return;
        vis[i] = 1;
        suspicious[i] = 1;
        for(auto it : graph[i]) {
            if(!vis[it]) {
                dfs(graph, it, suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<int> graph[n];
        for(int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            graph[u].push_back(v);
        }

        vector<int> suspicious(n, 0);
        suspicious[k] = 1;
        vis.assign(n, 0);
        dfs(graph, k, suspicious);
        
        unordered_set<int> st;
        vector<int> ans;
        vector<int> single(n, 0);

        bool f = false;
        
        for(int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if(suspicious[u] != suspicious[v]) {
                f = true;
                break;
            }
            else if(!suspicious[u] && !suspicious[v]) {
                st.insert(u);
                st.insert(v);
            }
            single[u] = 1;
            single[v] = 1;
        }

        if(f) {
            for(int i = 0; i < n; i++) {
                st.insert(i);
            }
            for(auto it : st) {
                ans.push_back(it);
            }
        }
        else {
            for(auto it : st) {
                ans.push_back(it);
            }
            for(int i = 0; i < single.size(); i++) {
                if(!single[i] && k != i) ans.push_back(i);
            }
        }

        return ans;

    }
};