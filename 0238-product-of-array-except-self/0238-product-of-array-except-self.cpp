class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        int a = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                a++;
                continue;
            }
            else p*=nums[i];
        }
        vector<int>v(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(a>1) return v;
            else if(a==1){
                if(nums[i]==0)nums[i]=p;
                else nums[i]=0;
            }
            else nums[i]=p/nums[i];
        }
        return nums;
    }
};