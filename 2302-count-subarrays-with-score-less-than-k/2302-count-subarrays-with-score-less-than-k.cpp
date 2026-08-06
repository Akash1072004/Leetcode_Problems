class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        int x=v.size();
        int i=0,j=0;
        long long score=0;
        long long count=0;
        while(i<x){
            while(j<x && (score+v[j])*(j-i+1)<k){
                score+=v[j++];
            }
            count+=j-i;
            score-=v[i];
            i++;
        }
        return count;
    }
};