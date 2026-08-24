class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& v, int i, int n, int k) {
        if(i > n) {
            if(v.size() == k) ans.push_back(v);
            return;
        }
        f(v, i+1, n, k);
        v.push_back(i);
        f(v, i+1, n, k);
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {

        vector<int> v;
        f(v, 1, n, k);
        return ans;

    }
};