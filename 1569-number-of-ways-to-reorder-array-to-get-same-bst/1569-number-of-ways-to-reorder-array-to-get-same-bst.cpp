class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;

    ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b % 2) res = a * res % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<ll> fact, infact;

    void precompute(ll n) {
        fact[0] = 1;

        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        infact[n] = power(fact[n], mod - 2);

        for (int i = n - 1; i >= 0; i--) {
            infact[i] = infact[i + 1] * (i + 1) % mod;
        }
    }

    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * infact[r] % mod * infact[n - r] % mod;
    }

    ll solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        ll a = solve(left);
        ll b = solve(right);

        ll ways = nCr(n - 1, left.size());
        ways = ways * a % mod;
        ways = ways * b % mod;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        fact.assign(n + 1, 0);
        infact.assign(n + 1, 0);

        precompute(n);

        return (solve(nums) - 1 + mod) % mod;
    }
};