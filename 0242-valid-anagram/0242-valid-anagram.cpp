class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> mp1,mp2;
        for(auto x : s){
            mp1[x]++;
        }
        for(auto x : t){
            mp2[x]++;
        }
        for(auto ele : mp1){
            char key = ele.first;
            int val = ele.second;

            if(mp2.count(key) == true){
                if(mp2[key] != val) return false;
            }else return false;
        }
        return true;
    }
};