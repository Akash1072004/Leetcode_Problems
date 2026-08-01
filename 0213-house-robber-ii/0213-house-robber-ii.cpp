class Solution {
public:
    int dp[101][2];
    int dp2[101][2];
    int f2(vector<int>&nums, int i, int flag){
        if(i == nums.size()-1) return 0;
        if(dp2[i][flag] != -1) return dp2[i][flag];
        if(flag) return dp2[i][flag] = f2(nums, i+1, false);
        return dp2[i][flag] = max(nums[i]+f2(nums, i+1, true), f2(nums, i+1, false));
    }
    int f(vector<int>&nums, int i, int flag){
        if(i >= nums.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(flag) return dp[i][flag] = f(nums, i+1, 0);
        return dp[i][flag] = max(nums[i]+f(nums, i+1, 1), f(nums, i+1, 0));
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() == 1) return nums[0];
        memset(dp, -1, sizeof dp);
        memset(dp2, -1, sizeof dp);
        return max(f(nums, 1, 0), f2(nums, 0, 0));


    }
};