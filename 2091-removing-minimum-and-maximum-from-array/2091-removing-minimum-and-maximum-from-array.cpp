class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int mini = 1e9;
        int maxi = -1e9;

        int minIdx = -1, maxIdx = -1;
        for(int i = 0; i < n; i++) {
            if(mini > nums[i]) {
                mini = nums[i];
                minIdx = i;
            }
            if(maxi < nums[i]) {
                maxi = nums[i];
                maxIdx = i;
            }
        }

        int ans = 1e9;
        ans = min(ans, max(minIdx, maxIdx)+1);
        ans = min(ans, n-min(minIdx, maxIdx));
        ans = min(ans, min(minIdx, maxIdx)+1+n-max(minIdx, maxIdx));

        return ans;

    }
};