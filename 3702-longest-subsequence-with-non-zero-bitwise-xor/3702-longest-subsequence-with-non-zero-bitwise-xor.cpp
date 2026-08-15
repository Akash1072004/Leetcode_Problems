class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == 0) return 0;
            else return 1;
        }
        int a = 0;
        bool f = false;
        for(int i = 0; i < n; i++) {
            a ^= nums[i];
            if(nums[i] != 0) f = true;
        }

        if(!f) return 0;

        if(a != 0) return n;
        for(int i = 0; i < n; i++) {
            if(a^ nums[i] != 0) return n-1;
        }
        return n-2;
    }
};