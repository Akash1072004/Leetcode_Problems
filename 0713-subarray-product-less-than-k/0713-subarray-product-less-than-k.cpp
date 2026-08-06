class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        if(k<=1)return 0;
        int x=v.size();
        int i=0,j=0;
        int count=0;
        int p=1;
        while(i<x){
            while(j<x && (p*v[j])<k){
                p*=v[j++];
            }
            count+=j-i;
            if(i<j) p=p/v[i];
            else j=i+1;
            i++;
        }   
        return count;
    }
};