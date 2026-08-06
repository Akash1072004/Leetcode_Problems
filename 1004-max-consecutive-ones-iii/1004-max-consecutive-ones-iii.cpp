class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int x=v.size();
        int i=0,j=0;
        int a=k;
        int ml=0;
        while(j<x){
          if(v[j]==1)j++;
          else if(v[j]==0){
            if(k!=0){
                k--;
                j++;
            }
            else {
                ml=max(ml,j-i);
                while(v[i]!=0)i++;
                i++;
                j++;
            }
          }
          ml=max(ml,j-i);
        }
        return ml;
    }
};