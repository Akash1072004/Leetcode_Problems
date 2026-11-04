class Solution {
public:
    int n, x, k;
    vector<int> nums;
    vector<long long> cost;
    vector<vector<long long>> dp;

    multiset<int> l, r;
    long long sl = 0, sr = 0;

    void balance() {
        while (l.size() > r.size() + 1) {
            int val = *l.rbegin();

            l.erase(l.find(val));
            sl -= val;

            r.insert(val);
            sr += val;
        }

        while (l.size() < r.size()) {
            int val = *r.begin();

            r.erase(r.begin());
            sr -= val;

            l.insert(val);
            sl += val;
        }
    }

    void add(int val) {
        if (l.empty() || val <= *l.rbegin()) {
            l.insert(val);
            sl += val;
        } else {
            r.insert(val);
            sr += val;
        }

        balance();
    }

    void remove(int val) {
        auto it = l.find(val);

        if (it != l.end()) {
            l.erase(it);
            sl -= val;
        } else {
            it = r.find(val);
            r.erase(it);
            sr -= val;
        }

        balance();
    }

    long long getCost() {
        long long med = *l.rbegin();

        return med * l.size() - sl + sr - med * r.size();
    }

    long long solve(int i, int cnt) {
        if (cnt == 0) {
            return 0;
        }

        if (i >= n || n - i < cnt * x) {
            return 1e18;
        }

        if (dp[i][cnt] != -1) {
            return dp[i][cnt];
        }

        long long ans = solve(i + 1, cnt);

        ans = min(ans, cost[i] + solve(i + x, cnt - 1));

        return dp[i][cnt] = ans;
    }

    long long minOperations(vector<int>& arr, int sz, int cnt) {
        nums = arr;
        n = nums.size();
        x = sz;
        k = cnt;

        cost.resize(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return solve(0, k);
        
    }
};