class Solution {
public:
    typedef pair<int,int>pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==0)return {};
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(auto ele : map){
            int element = ele.first;
            int freq = ele.second;
            pair<int,int>p = {freq,element};
            pq.push(p);
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        

    }
};