class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }

        while(!q.empty()) {
            int node = q.front();

            for(auto ele : graph[node]) {
                indegree[ele]--;
                if(indegree[ele] == 0) {
                    q.push(ele);
                    vis[ele] = true;
                }
            }

            q.pop();
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] != 0) return false;
        }

        return true;
        

    }
};