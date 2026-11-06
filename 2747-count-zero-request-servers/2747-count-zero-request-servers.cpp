class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), cmp);

        int m = queries.size();

        vector<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n+1, 0);
        vector<int> ans(m);

        int l = 0, r = 0, cnt = 0;

        for(auto it : q) {
            int start = it.first - x;
            int end = it.first;

            while(r < logs.size() && logs[r][1] <= end) {
                int id = logs[r][0];
                if(freq[id] == 0) {
                    cnt++;
                }
                freq[id]++;
                r++;
            }
            while(l < r && logs[l][1] < start) {
                int id = logs[l][0];
                freq[id]--;
                if(freq[id] == 0) {
                    cnt--;
                }
                l++;
            }

            ans[it.second] = n - cnt;
        }

        return ans;

    }
};