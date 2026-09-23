class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
            totalSum += nums[i];
        }

        if(totalSum < x) return -1;

        int target = totalSum - x;

        int longestSubarrayLength = -1e9;
        sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int remainingSum = sum - target;
            if(mp.find(remainingSum) != mp.end()) {
                int idx = mp[remainingSum];
                longestSubarrayLength = max(longestSubarrayLength, i-idx);
            }
        }

        if(longestSubarrayLength == -1e9) return -1;

        return n-longestSubarrayLength;

    }
};