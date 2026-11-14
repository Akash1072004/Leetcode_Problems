class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int x=v.size();
        if(x!=1){
            if(k>=x)k=k%x;
            vector<int>a(x);
        int b=x-k,c=0;
        for(int i=0;i<k;i++){
            a[c++]=v[b++];
        }
        for(int i=0;i<x-k;i++){
            a[c++]=v[i];
        }
        for(int i=0;i<x;i++){
            v[i]=a[i];
        }
        }
    }
};