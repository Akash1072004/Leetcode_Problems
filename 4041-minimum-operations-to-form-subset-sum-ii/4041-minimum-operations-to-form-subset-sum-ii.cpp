class Solution {
public:
    int dp[101][5001];
    int f(vector<int>& nums, int sum, int i, int n) {
        if(sum == 0) return 0;
        if(i >= n || sum < 0) return 1e9;

        if(dp[i][sum] != -1) return dp[i][sum];

        int ans = 1e9;
        int a = nums[i];
        int count = 0;
        while(a > 0) {
            int x = a;
            int b = count;
            while(x <= sum) {
                ans = min(ans, b+f(nums, sum-x, i+1, n));
                x *= 2;
                b++;
            }
            a /= 2;
            count++;
        }
        ans = min(ans, f(nums, sum, i+1, n));
        return dp[i][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        int ans = f(nums, sum, 0, n);
        if(ans == 1e9) return -1;
        return ans;

    }
};