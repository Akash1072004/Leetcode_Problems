class Solution {
public:
    #define ll long long
    vector<vector<pair<ll, vector<int>>>> dp;
    void findNextIdx(vector<int>& nextIndex, vector<vector<int>>& v) {
        int n = v.size();
        
        for(int i = 0; i < n; i++) {
            int low = 0, high = n-1;
            int ans = n;

            while(low <= high) {
                int mid = low + (high-low)/2;

                if(v[mid][0] > v[i][1]) {
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            nextIndex[i] = ans;
        }
    }

    pair<ll, vector<int>> f(vector<int>& nextIndex, vector<vector<int>>& v, int i, int k) {
        if(i >= v.size() || k == 0) return {0, {}};
        if(dp[i][k].first != -1) return dp[i][k];
        ll res = 0;
        auto notTake = f(nextIndex, v, i+1, k);
        
        auto take = f(nextIndex, v, nextIndex[i], k-1);

        take.first += v[i][2];
        take.second.push_back(v[i][3]);

        sort(take.second.begin(), take.second.end());

        if(take.first > notTake.first) {
            return dp[i][k] = take;
        }
        if(take.first == notTake.first && take.second < notTake.second) {
            return dp[i][k] = take;
        }
        return dp[i][k] = notTake;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> v(n, vector<int> (4));
        for(int i = 0; i < n; i++) {
            v[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(v.begin(), v.end());

        vector<int> nextIndex(n);
        findNextIdx(nextIndex, v);

        dp.assign(n, vector<pair<ll, vector<int>>>(5, {-1, {}}));

        auto ans = f(nextIndex, v, 0, 4);

        return ans.second;

    }
};