class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        sort(v.begin(), v.end());

        vector<int> temp;
        temp.push_back(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(v[i] != v[i-1]){
                temp.push_back(v[i]);
            }
        }
        v = temp;

        int m = v.size();

        vector<int> arr(m);

        for(int i = 1; i < m; i++){
            if(v[i] - v[i-1] > maxDiff){
                arr[i] = arr[i-1] + 1;
            }
            else{
                arr[i] = arr[i-1];
            }
        }

        int LOG = 19;
        vector<vector<int>> dp(LOG, vector<int>(m));

        for(int i = 0; i < m; i++){
            int j = upper_bound(v.begin(), v.end(), v[i] + maxDiff) - v.begin();
            dp[0][i] = j-1;
        }

        for(int k = 1; k < LOG; k++){
            for(int i = 0; i < m; i++){
                dp[k][i] = dp[k-1][dp[k-1][i]];
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            int u = q[0];
            int w = q[1];

            if(u == w){
                ans.push_back(0);
                continue;
            }
            if(nums[u] == nums[w]){
                ans.push_back(1);
                continue;
            }

            int x = min(nums[u], nums[w]);
            int y = max(nums[u], nums[w]);

            int l = lower_bound(v.begin(), v.end(), x) - v.begin();
            int r = lower_bound(v.begin(), v.end(), y) - v.begin();

            if(arr[l] != arr[r]){
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int cnt = 0;

            for(int k = LOG - 1; k >= 0; k--){
                if(dp[k][cur] < r){
                    cur = dp[k][cur];
                    cnt += (1 << k);
                }
            }
            ans.push_back(cnt+1);
        }
        return ans;
    }
};