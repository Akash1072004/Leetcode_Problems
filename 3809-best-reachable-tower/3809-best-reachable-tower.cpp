class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        
        int best = -1;
        vector<int> ans = {-1, -1};
        for(auto it : towers) {
            int x = it[0];
            int y = it[1];
            int q = it[2];
            int dist = abs(x-center[0]) + abs(y-center[1]);
            if(dist <= radius) {
                if(q > best) {
                    best = q;
                    ans = {x, y};
                }
                else if(q == best) {
                    if(x < ans[0] || (x == ans[0] && y < ans[1])) {
                        ans = {x, y};
                    }
                }
            }
        }

        return ans;


    }
};