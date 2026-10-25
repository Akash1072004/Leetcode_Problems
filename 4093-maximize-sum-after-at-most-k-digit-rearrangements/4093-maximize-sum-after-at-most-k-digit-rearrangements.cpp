class Solution {
public:
    // static bool cmp(pair<int, int> a, pair<int, int> b) {
    //     return a.first > b.first;
    // }

    long long maximizeSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<pair<int, int>> v;
        long long result = 0;

        for(int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            sort(s.rbegin(), s.rend());

            v.push_back({stoi(s) - nums[i], i});
            result += nums[i];
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i < k; i++) {
            int idx = v[i].second;
            string temp = to_string(nums[idx]);
            sort(temp.rbegin(), temp.rend());

            result += stoi(temp) - nums[idx];
        }

        return result;
    }
};