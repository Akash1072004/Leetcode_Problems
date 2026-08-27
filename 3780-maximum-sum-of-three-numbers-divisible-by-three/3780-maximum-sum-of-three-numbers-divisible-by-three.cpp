class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        vector<int> v[3];
        for(int x : nums) {
            v[x % 3].push_back(x);
        }
        for(int i = 0; i < 3; i++) {
            sort(v[i].rbegin(), v[i].rend());
        }
        
        int ans = 0;
        if(v[0].size() >= 3) {
            ans = max(ans, v[0][0] + v[0][1] + v[0][2]);
        }
        if(v[1].size() >= 3) {
            ans = max(ans, v[1][0] + v[1][1] + v[1][2]);
        }
        if(v[2].size() >= 3) {
            ans = max(ans, v[2][0] + v[2][1] + v[2][2]);
        }
        if(v[0].size() >= 1 && v[1].size() >= 1 && v[2].size() >= 1) {
            ans = max(ans, v[0][0] + v[1][0] + v[2][0]);
        }
        
        return ans;
        
    }
};