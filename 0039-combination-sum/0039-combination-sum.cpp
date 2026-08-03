class Solution {
public:
    void f(vector<int>&v, int target, vector<vector<int>>&ans, int i, vector<int>c){
        if(target == 0){
            ans.push_back(c);
            return;
        }
        if(i == v.size() || target < 0)return;
        // Take 
        c.push_back(v[i]);
        f(v,target - v[i],ans,i,c);
        c.pop_back();
        // NotTake
        f(v,target,ans,i+1,c);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        f(v,target,ans,0,{});
        return ans;

    }
};