class Solution {
public:
    vector<int> runningSum(vector<int>& v) {
        int x = v.size();
        int s = 0;
        for(int i=0;i<x;i++){
            if(i==0)continue;
            else v[i]=v[i]+v[i-1];
        }
        return v;
    }
};