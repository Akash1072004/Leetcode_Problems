class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int s = target-nums[i];
            if(map.find(s)!=map.end()){
                ans.push_back(i);
                ans.push_back(map[s]);
                return ans;
            }
            else map[nums[i]]=i;
        }
        return ans;
    }
};