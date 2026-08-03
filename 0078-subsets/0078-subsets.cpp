class Solution {
public:
    void s(vector<int>& v,vector<int>h,int i,vector<vector<int>>&ans){
        if(i==v.size()){
            ans.push_back(h); 
            return;
        }
        s(v,h,i+1,ans);
        h.push_back(v[i]);
        s(v,h,i+1,ans);

    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<int>h;
        vector<vector<int>>ans;
        s(v,h,0,ans);
        return ans;

    }
};