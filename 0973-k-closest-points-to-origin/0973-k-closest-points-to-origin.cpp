class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        int x = v.size();
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0;i<x;i++){
            int c1 = v[i][0];
            int c2 = v[i][1];
            int dist = (c1*c1)+(c2*c2);
            pq.push({dist,v[i]});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            vector<int>vec = pq.top().second;
            ans.push_back(vec);
            pq.pop();
        }
        return ans;


    }
};