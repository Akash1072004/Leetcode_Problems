class Solution {
public:
    int n; 
    int dp[51][51][201];
    int f(vector<vector<int>>& graph, int mouse, int cat, int steps) {
        if(mouse == 0) return 1; // mouse win
        if(cat == mouse) return 2; // cat win
        if(steps > 150) return 0; // match draw

        if(dp[mouse][cat][steps] != -1) return dp[mouse][cat][steps];
        
        int ans = 0;
        if(!(steps & 1)) { // mouse turn
            int ans = 1;
            for(auto it : graph[mouse]) {
                int res = f(graph, it, cat, steps+1);
                if(res == 1) return dp[mouse][cat][steps] = 1;
                if(res == 0) ans = 0;
            }
            if(ans == 0) return dp[mouse][cat][steps] =  0;
            else return dp[mouse][cat][steps] =  2;
        }
        else { // cat turn
            int ans = 2;
            for(auto it : graph[cat]) {
                if(it == 0) continue;
                int res = f(graph, mouse, it, steps+1);
                if(res == 2) return dp[mouse][cat][steps] =  2;
                if(res == 0) ans = 0;
            }
            if(ans == 0) return dp[mouse][cat][steps] =  0;
            else return dp[mouse][cat][steps] =  1;
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        
        n = graph.size();

        memset(dp, -1, sizeof dp);

        return f(graph, 1, 2, 0);

    }
};