class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        int n = nums.size();
        int result = 0;

        for(int i = 0; i < n; i++) {
            long long LCM = 1, gcd = 0, product = 1;
            for(int j = i; j < n; j++) {
                if(product > 1e18 / nums[j]) break;
                product *= nums[j];

                gcd = __gcd(gcd, (long long)nums[j]);

                long long g = __gcd(LCM, (long long)nums[j]);
                LCM = (LCM / g) * nums[j];

                if(product == LCM* gcd) {
                    result = max(result, j-i+1);
                }
            }
        }

        return result;
    }
};