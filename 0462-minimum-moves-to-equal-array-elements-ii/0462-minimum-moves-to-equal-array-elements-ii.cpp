class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        long long curr = 0;
        long long ans = 1e18;

        for(int i = 0; i < n; i++) {
            long long left = 0,right = 0;

            if(i+1 < n) {
                right = sum - curr - nums[i] - (n - 1-i)* 1LL* nums[i]; 
            }

            left = i* 1LL* nums[i] - curr;
            ans = min(ans, left + right);
            curr = curr + nums[i];
        }

        return ans;


    }
};