class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> rev(n, vector<int> ());

        vector<int> indegree(n, 0);

        for(int node = 0; node < n; node++) {
            for(int ele : graph[node]) {
                rev[ele].push_back(node);
                indegree[node]++;
            }
        }

        queue<int> q;

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }

        vector<int> totalSafeNode;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            totalSafeNode.push_back(node);

            for(int ele : rev[node]) {
                if(!vis[ele]) {
                    indegree[ele]--;
                    if(indegree[ele] == 0) {
                        q.push(ele);
                        vis[ele] = true;
                    }
                }
            }
        }

        sort(totalSafeNode.begin(), totalSafeNode.end());

        return totalSafeNode;

    }
};