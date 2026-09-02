class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();
        
        int mini = 1e9;
        bool check = false;
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums1[i]);
            if(i > 0 && (nums1[i] & 1) && !(nums1[i-1] & 1)) check = true;
            if(i > 0 && !(nums1[i] & 1) && (nums1[i-1] & 1)) check = true;
        }

        if(!check) return true;

        if(mini & 1) return true;
        else return false;

    }
};