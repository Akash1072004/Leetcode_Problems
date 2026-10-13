class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }

        for(int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }

        sort(nums.rbegin(), nums.rend());

        long long ans = 0;

        int i = 0, j = n-1;
        while(i < j) {
            ans += ((nums[i]* 1LL* nums[i]) - (nums[j]* 1LL* nums[j]));
            i++, j--;
        }

        if(n & 1) ans += (nums[i]* 1LL* nums[i]);

        return ans;

    }
};