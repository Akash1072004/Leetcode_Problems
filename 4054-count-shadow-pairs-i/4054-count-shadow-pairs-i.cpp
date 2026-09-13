class Solution {
public:
    #define ll long long
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nxt(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(!st.empty()) nxt[i] = st.top();
            st.push(i);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int r = nxt[i];
            auto &v = mp[nums[i]];

            int l = upper_bound(v.begin(), v.end(), i)-v.begin();
            int rr = lower_bound(v.begin(), v.end(), r)-v.begin();
            int same = rr - l;
            ans += (r-i-1)-same;
        }
        return ans;
    }
};