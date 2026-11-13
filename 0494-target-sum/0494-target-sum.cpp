class Solution {
public:
    int dp[21][4005];
    int f(vector<int>& nums, int target, int i){
        if(i == nums.size()) {
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[i][target+1003] != -1) return dp[i][target+1003];
        return dp[i][target+1003] = f(nums, target - nums[i], i+1) + f(nums, target + nums[i], i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1 and target ==  0) return 2;
        if(nums.size() == 1 and target ==  nums[0]) return 1;
        memset(dp, -1, sizeof dp);
        return f(nums, target, 0);


    }
};