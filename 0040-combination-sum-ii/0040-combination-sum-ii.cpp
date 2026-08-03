class Solution {
public:
    void f(vector<int>&v, int target, vector<vector<int>>&ans,vector<int>c,int i){
        if(i == v.size()){
            if(target == 0) ans.push_back(c);
            return;
        }

        if(target == 0){
            ans.push_back(c);
            return;
        }
        if(target < 0)return;
        // Take 
        c.push_back(v[i]);
        f(v,target - v[i],ans,c,i+1);
        c.pop_back();
        // NotTake
        int j = i;
        while(j+1 < v.size() && v[j] == v[j+1])j++;
        f(v,target,ans,c,j+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        f(v,target,ans,{},0);
        return ans;


    }
};