class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> graph(n, vector<int> (n, 1e9));

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u][v] = wt;
            graph[v][u] = wt;
        }

        for(int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }

        int count = 0; int ans = 0;
        int minCount = 1e9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] <= distanceThreshold) count++;
            } 
            if(minCount >= count) {
                minCount = count;
                ans = i;
            }
            count = 0;
        }

        return ans;

        

    }
};