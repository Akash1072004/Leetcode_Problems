class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int lcm = 1;
            for(int j = i; j < n; j++) {
                if(k % nums[j] != 0) break;
                lcm = lcm / gcd(lcm, nums[j])* nums[j];
                if(lcm == k) ans++;
                if(lcm > k) break;
            }
        }

        return ans;


    }
};