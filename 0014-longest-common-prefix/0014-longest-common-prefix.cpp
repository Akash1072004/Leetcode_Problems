class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int x=strs.size();
         if(strs.size()==1)return strs[0];
         sort(strs.begin(),strs.end());
    string m=strs[0];
    string n=strs[x-1];
    string s="";
    for(int i=0;i<min(strs[0].size(),strs[x-1].size());i++){
        if(m[i]==n[i]){
            s=s+m[i];
        }
        else return s;
    }
    return s;
    }
};