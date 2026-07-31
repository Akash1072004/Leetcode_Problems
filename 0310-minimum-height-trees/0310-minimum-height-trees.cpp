class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<int> graph[n];

        vector<int> indegree(n, 0);
        for(int i = 0; i < n-1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> qu;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) qu.push(i);
        }   

        vector<int> vis(n, 0);

        int rem = n;
        while(rem > 2) {
            int size = qu.size();
            rem -= size;
            while(size--) {
                int node = qu.front();
                vis[node] = 1;
                qu.pop();
                for(auto it : graph[node]) {
                    if(!vis[it]) {
                        indegree[it]--;
                        if(indegree[it] == 1) {
                            qu.push(it);
                        }
                    }
                }
            }
        }

        vector<int> ans;
        while(!qu.empty()) {
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
        }

        return ans;

    }
};