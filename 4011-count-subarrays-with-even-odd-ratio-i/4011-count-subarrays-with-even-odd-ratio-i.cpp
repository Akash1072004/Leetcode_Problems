class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size();
        int x = 0, y = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            x = 0, y = 0;
            if(nums[i] & 1) y++;
            else x++;
            if(x * b <= a* y) ans++;
            for(int j = i+1; j < n; j++) {
                if(nums[j] & 1) y++;
                else x++;
                if(x * b <= a* y) ans++;
            }
        }

        return ans;
        
    }
};