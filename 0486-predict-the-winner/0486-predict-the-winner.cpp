class Solution {
public:
    int f(vector<int>& nums, int i, int j, bool turn) {
        if(i > j) return 0;
        int ans = 0;
        if(!turn) {
            ans = -1e9;
            ans = max(ans, nums[i]+f(nums, i+1, j, true));
            ans = max(ans, nums[j]+f(nums, i, j-1, true));
        }
        else {
            ans = 1e9;
            ans = min(ans, -nums[i]+f(nums, i+1, j, false));
            ans = min(ans, -nums[j]+f(nums, i, j-1, false));
        }

        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();
        
        int ans = f(nums, 0, n-1, false);

        return (ans >= 0) ? true : false;

    }
};