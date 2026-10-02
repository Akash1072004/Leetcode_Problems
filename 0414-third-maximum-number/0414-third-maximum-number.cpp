class Solution {
public:
    int thirdMax(vector<int>& nums) {

        int n = nums.size();

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;

        for(int i = 0; i < n; i++) {
            firstMax = max(firstMax, nums[i]);
        }

        bool foundSecond = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] == firstMax) continue;
            if(!foundSecond || nums[i] > secondMax) {
                secondMax = nums[i];
                foundSecond = true;
            }
        }

        if(!foundSecond) return firstMax;

        bool foundThird = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] == firstMax || nums[i] == secondMax) continue;
            if(!foundThird || nums[i] > thirdMax) {
                thirdMax = nums[i];
                foundThird = true;
            }
        }

        if(!foundThird) return firstMax;

        return thirdMax;


    }
};