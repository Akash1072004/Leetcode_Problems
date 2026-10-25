class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1e9;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp) {
            vector<int> v = it.second;
            for(int i = 2; i < v.size(); i++) {
                ans = min(ans, 2* (v[i] - v[i-2]));
            }
        }

        if(ans == 1e9) return -1;
        return ans;

    }
};