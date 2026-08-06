class Solution {
public:
    int bestClosingTime(string s) {
        int x = s.size();
    int a = 0,b=0,m=INT_MAX;
    vector<int>v(x,0);
    int idx=0;
    for(int i=0;i<x;i++){
        if(s[i]=='Y')a++;
        else b++;
    }
    v[0]=a;
    if(v[0]<m){
        idx=0;
        m=v[0];
    }
    for(int i=1;i<x;i++){
        if(s[i-1]=='Y')a--;
        else a++;
        v[i]=a;
        if(v[i]<m){
            idx=i;
            m=v[i];
        }
    }
    if(b<m){
            idx=x;
            m=b;
        }
    return idx;
    }
};