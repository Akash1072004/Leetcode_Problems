class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        if(k==1)return v;
        int x = v.size();
        deque<int>dq;
        vector<int>ans;
        int count=0;
        int i=0,j=0;
        while(i<x){
            while(dq.size()>0 && v[i]>=v[dq.back()])dq.pop_back();
            dq.push_back(i);
            while(dq.size()>0 && dq.front()<j)dq.pop_front();
            count++;
            if(count==k){
                ans.push_back(v[dq.front()]);
                count--;
                j++;
            }
            i++;
        }
        return ans;

    }
};