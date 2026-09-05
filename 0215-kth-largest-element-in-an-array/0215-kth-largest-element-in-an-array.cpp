class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int x = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<x;i++){
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();


    }
};