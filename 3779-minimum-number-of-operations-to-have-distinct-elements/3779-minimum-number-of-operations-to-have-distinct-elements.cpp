class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100001, 0);
        for(int x : nums) {
            freq[x]++;
        }
        int duplicate = 0;
        for(int x = 1; x <= 100000; x++) {
            if(freq[x] > 1) {
                duplicate++;
            }
        }
        int ans = 0;
        int i = 0;
        while(i < n && duplicate > 0) {
            for(int j = 0; j < 3 && i < n; j++) {
                if(freq[nums[i]] == 2) {
                    duplicate--;
                }
                freq[nums[i]]--;
                i++;
            }
            ans++;
        }
        
        return ans;
        
    }
};