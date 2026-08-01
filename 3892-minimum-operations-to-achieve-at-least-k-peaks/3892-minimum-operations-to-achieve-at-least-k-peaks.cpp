class Solution {
public:
    int n;
    vector<vector<array<int,2>>> dp;    
    int f(vector<int>& cost, int i, int k, bool flag) {
        if(k == 0) return 0;
        if(i >= n) return 1e9;
        if(dp[i][k][flag] != -1) return dp[i][k][flag];
        if(flag) {
            if(i == n-1) return dp[i][k][flag] = f(cost, i+1, k, flag);
        } 
        return dp[i][k][flag] = min(cost[i] + f(cost, i+2, k-1, (i == 0 || flag) ? true : false), f(cost, i+1, k, flag));
    }

    int minOperations(vector<int>& nums, int k) {
        n = nums.size();

        if(k >  n/2) return -1;

        int count = 0;

        if(n == 1) return (k <= 1 ? 0 : -1);

        for(int i = 1; i < n; i++) {
            int left = (i == 0) ? nums[n-1] : nums[i-1];
            int right = (i == n-1) ? nums[0] : nums[i+1];
            if(nums[i] > left && nums[i] > right) count++;
            if(count >= k) return 0;
        }

        vector<int> cost(n);

        for(int i = 0; i < n; i++) {
            int left = (i == 0) ? nums[n-1] : nums[i-1];
            int right = (i == n-1) ? nums[0] : nums[i+1];
            cost[i] = max(0, max(left, right)-nums[i]+1);
        }

        dp.assign(n + 2, vector<array<int,2>>(k + 1, {-1, -1}));

        int ans = f(cost, 0, k, false);
        return (ans == 1e9) ? -1 : ans;
    }
};