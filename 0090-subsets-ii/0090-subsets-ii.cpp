class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&v, int i, vector<int>temp, bool flag){
        if(i == v.size()){
            ans.push_back(temp);
            return;
        }
        if(i > 0 and v[i] == v[i-1] and flag == false) {
            f(v,i+1,temp,false);
        }
        else {
            f(v,i+1,temp,false);
            temp.push_back(v[i]);
            f(v,i+1,temp,true);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        f(nums,0,{},false);
        return ans;

    }
};