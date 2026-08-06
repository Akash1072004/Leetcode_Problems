class Solution {
public:

    int isTrue(int mid, vector<int>& nums, int target) {

        int sum = 0;

        for(int i = 0; i < mid; i++) {
            sum += nums[i];
        }

        if(sum >= target) return true;

        int i = 0; int j = mid;

        while(j < nums.size()) {
            sum = sum + nums[j] - nums[i];
            if(sum >= target) return true;
            i++; j++;
        }

        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int low = 1, high = n;

        int minLength = 1e9;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isTrue(mid, nums, target)) {
                minLength = min(minLength, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return (minLength == 1e9) ? 0 : minLength;


    }
};