class Solution {
public:
    int dp[2501][2502];
    int f(vector<int>& nums, int i, int prev) {
        if(i >= nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int ans = 0;
        if(prev == -1) {
            ans = max(ans, 1+f(nums, i+1, i));
            ans = max(ans, f(nums, i+1, prev));
        }
        else {
            if(nums[i] > nums[prev]) {
                ans = max(ans, 1+f(nums, i+1, i));
            }
            ans = max(ans, f(nums, i+1, prev));
        }

        return dp[i][prev+1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(nums, 0, -1);
    }
};