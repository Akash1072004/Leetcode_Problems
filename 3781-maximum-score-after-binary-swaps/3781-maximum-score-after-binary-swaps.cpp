class Solution {
public:
    #define ll long long 
    long long maximumScore(vector<int>& nums, string s) {
        
        int n = nums.size();
        priority_queue<int> pq;
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);

            if(s[i] == '1') {
                ans += pq.top();
                pq.pop();
            }
        }

        return ans;
        
    }
};