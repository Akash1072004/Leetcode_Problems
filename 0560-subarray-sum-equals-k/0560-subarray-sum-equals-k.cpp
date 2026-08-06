class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int x = nums.size();
        unordered_map<int,int>map;
        vector<int>pre(x);
        pre[0]=nums[0];
        for(int i=1;i<x;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<x;i++){
            if(pre[i]==k)count++;
            int rem = pre[i]-k;   
            if(map.find(rem)!=map.end())count+=map[rem];
            map[pre[i]]++;

        }
        return count;
        

    }
};