class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        int p=1;
        int idx=-1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                count++;
                idx=i;
                continue;
            }
            p *= nums[i];
        }

        vector<int> ans(n, 0);
        // for(int i = 0; i < n; i++) {
        //     ans[i] = 0;
        // }

        if(count > 1) return ans;
        if(count == 1){
            ans[idx]=p;
            return ans;
        }
        for(int i = 0; i < n; i++) {

            ans[i]=p/nums[i];

        }
        return ans;


    }
};