class Solution {
public:
    int dp[301][301];
    int f(vector<int>& nums, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k = i; k <= j; k++){
            // Think in reverse Order like last ballon left 
            ans = max(ans, (nums[i-1]*nums[k]*nums[j+1]) + f(nums, i, k-1) + f(nums, k+1, j));
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        return f(nums, 1, n-2);


    }
};