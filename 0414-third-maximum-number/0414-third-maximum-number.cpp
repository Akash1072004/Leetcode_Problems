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

        bool flag1 = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] == firstMax) continue;
            if(!flag1 || nums[i] > secondMax) {
                secondMax = nums[i];
                flag1 = true;
            }
        }

        if(!flag1) return firstMax;

        bool flag2 = false;

        for(int i = 0; i < n; i++) {
            if(nums[i] == firstMax || nums[i] == secondMax) continue;
            if(!flag2 || nums[i] > thirdMax) {
                thirdMax = nums[i];
                flag2 = true;
            }
        }

        if(!flag2) return firstMax;

        return thirdMax;


    }
};