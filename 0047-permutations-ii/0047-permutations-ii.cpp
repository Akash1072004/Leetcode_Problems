class Solution {
public:
    set<vector<int>> uniqueArray;
    int n;
    void f(vector<int>& nums, vector<int>& temp, vector<int>& vis) {
        if(temp.size() == nums.size()) {
            uniqueArray.insert(temp);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            temp.push_back(nums[i]);

            f(nums, temp, vis);

            temp.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        n = nums.size();

        // sort(nums.begin(), nums.end());

        vector<int> temp;

        vector<int> vis(n, 0);
        f(nums, temp, vis);

        vector<vector<int>> result;
        for(auto it : uniqueArray) {
            result.push_back(it);
        }

        return result;

    }
};