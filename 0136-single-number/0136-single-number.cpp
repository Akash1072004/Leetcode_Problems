class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(st.count(nums[i])){
                st.erase(nums[i]);
            }
            else st.insert(nums[i]);
        }
        for(auto ele:st){
            return ele;
        }
        return 0;
    }
};