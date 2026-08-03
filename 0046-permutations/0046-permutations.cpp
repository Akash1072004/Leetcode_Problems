class Solution {
public: 
    vector<vector<int>> ans;

    void f(vector<int>& nums, vector<int>& temp, int i, vector<int>& used) {

        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int j = 0; j < nums.size(); j++) {
            if(used[j]) continue;
            temp.push_back(nums[j]);
            used[j] = 1;
            f(nums, temp, i+1, used);
            temp.pop_back();
            used[j] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;

        vector<int> used(n, 0);

        f(nums, temp, 0, used);

        return ans;


    }
};