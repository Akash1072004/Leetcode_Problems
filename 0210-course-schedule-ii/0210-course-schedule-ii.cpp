class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<vector<int>> graph (numCourses, vector<int> ());

        // form Graph
        for(int i = 0; i < n; i++) {
            int parent = prerequisites[i][1];
            int child = prerequisites[i][0];
            graph[parent].push_back(child);
        }

        // Detect Cycle using Topological sort
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto ele : graph[i]) {
                indegree[ele]++;
            }
        }

        queue<int> q;
        vector<bool> vis(numCourses, false);

        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }


        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);

            for(auto ele : graph[node]) {
                indegree[ele]--;
                if(indegree[ele] == 0) {
                    q.push(ele);
                    vis[ele] = true;
                }
            }

            q.pop();
        }

        if(ans.size() < numCourses) return {};
        else return ans;

    }
};