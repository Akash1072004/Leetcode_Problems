class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        
        unordered_map<int, int> mp;
        int n = x.size(); 

        for(int i = 0; i < n; i++) {
            mp[x[i]]=max(mp[x[i]],y[i]);
        }

        vector<int> v;
        for(auto it : mp) v.push_back(it.second);
        if(v.size() < 3) return -1;

        sort(v.rbegin(),v.rend());

        return v[0]+v[1]+v[2];



    }
};