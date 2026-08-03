class Solution {
public:
    int sum2, n;
    bool f(vector<int>& nums, int i, int k, int sum, int &mask) {
        if(k == 1) return true;
        if(sum < 0) return false;
        if(i == n) return false;
        if(sum == 0) return f(nums, 0, k-1, sum2, mask);
        if((mask & (1<<i)) == 0) return f(nums, i+1, k, sum, mask);
        bool ans = false;
        mask = mask ^ (1 << i);
        ans |= f(nums, i+1, k, sum - nums[i], mask);
        mask = mask | (1 << i);

        ans |= f(nums, i+1, k, sum, mask);

        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % k != 0) return false;

        sum /= k;
        sum2 = sum;

        sort(nums.begin(), nums.end(), greater<int> ());

        int mask = (1 << n) - 1;

        return f(nums, 0, k, sum, mask);
        
    }
};