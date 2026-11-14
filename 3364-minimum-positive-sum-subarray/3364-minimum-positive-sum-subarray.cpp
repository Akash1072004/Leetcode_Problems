class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int n = nums.size();

        int minSum = 1e9;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            int len = 0;

            for(int j = i; j < n; j++) {
                sum += nums[j];
                len++;

                if(len >= l && len <= r && sum > 0) {
                    minSum = min(minSum, sum);
                }

                if(len == r) break;
            }
        }

        return minSum == 1e9 ? -1 : minSum;

        
    }
};