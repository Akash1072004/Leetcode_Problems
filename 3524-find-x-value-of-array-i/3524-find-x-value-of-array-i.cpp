class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;
    ll f(vector<int>& nums, int k, int i, int val, int req) {
        if(i >= nums.size()) return 0;
        if(dp[i][val] != -1) return dp[i][val];
        ll ans = 0;
        int newVal = (1LL * val * (nums[i] % k)) % k;
        if(newVal == req) ans++;
        ans += f(nums, k, i+1, newVal, req);
        return dp[i][val] = ans;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<ll> result(k, 0);
        for(int i = 0; i < k; i++) {
            dp.assign(n+1, vector<ll>(k, -1));
            for(int j = 0; j < n; j++) {
                result[i] += f(nums, k, j, 1% k, i);
            }
        }
        return result;

    }
};