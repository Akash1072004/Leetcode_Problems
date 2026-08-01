class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int x = v.size();
    sort(v.begin(),v.end());
    int ps = 0;
    int ns = 0;
    for(int i=0;i<x;i++){
        if(v[i]<0)ns+=v[i];
        else ps+=v[i];
    }
    ns=(-1)*ns;
    if(ps>=ns) {
        int sum = 0;
        int a = 1;
        for(int i=0;i<x;i++){
            sum = sum + (a*v[i]);
            a++;
        }
        return sum;
    }
    else {
        int i=0;
        while(ns>ps){
            ns=ns+v[i];
            i++;
        }
        int sum = 0;
        int a = 1;
        for(int j=i;j<x;j++){
            sum = sum + (a*v[j]);
            a++;
        }
        return sum;
    }
    }
};