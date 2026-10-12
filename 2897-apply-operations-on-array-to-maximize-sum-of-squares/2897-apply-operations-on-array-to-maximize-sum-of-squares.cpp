class Solution {
public:
    #define MOD 1000000007
    int maxSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> setBits(32, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1 << j)) { // jth bit set of nums[i]
                    setBits[j]++; // increase the count of the set bits in the jth positions 
                }
            }
        }

        long long result = 0;

        while(k--) {
            int cur = 0;
            for(int i = 0; i < 32; i++) {
                if(setBits[i] > 0) {
                    setBits[i]--;

                    cur |= (1 << i);
                }
            }

            result = (result + (cur* 1LL* cur)) % MOD;
        }

        return result;

    }
};