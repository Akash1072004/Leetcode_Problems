class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n = nums.size();

        ll cnt = 0;

        ll a = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] >= minK && nums[i] <= maxK) {
                cnt++;
                a++;
            }
            else {
                cnt += ((a* (a+1))/ 2) - a;
                a = 0;
            }
        }

        if(a > 0) cnt += ((a* (a+1))/ 2) - a;

        return cnt;
        
    }
};