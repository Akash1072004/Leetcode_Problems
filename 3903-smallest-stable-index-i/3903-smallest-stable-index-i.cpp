class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        
        int maxi = nums[0];
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);
        for(int i = 0; i < n; i++) {
            prefixMax[i] = max(nums[i], maxi);
            maxi = max(maxi, nums[i]);
        }
        
        int mini = nums[n-1];
        for(int i = n-1; i >= 0; i--) {
            suffixMin[i] = min(nums[i], mini);
            mini = min(mini, nums[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(prefixMax[i] - suffixMin[i] <= k) return i;
        }

        return -1;

    }
};