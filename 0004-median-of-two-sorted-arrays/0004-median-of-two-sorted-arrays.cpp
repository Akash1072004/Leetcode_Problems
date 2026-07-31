class Solution {
public:
    double findMedianSortedArrays(vector<int>& v, vector<int>& v1) {
        int x=v.size();
        int y=v1.size();
        int s=(x+y)/2;
        double m=0;
        vector<double>a(x+y);
        int i=0,j=0,k=0;
        while(i<x && j<y){
            if(v[i]<v1[j])a[k++]=v[i++];
            else a[k++]=v1[j++];
        }
        if(i==x)while(j<y)a[k++]=v1[j++];
        else while(i<x)a[k++]=v[i++];
        if((x+y)%2==0)m=(a[s]+a[s-1])/2.0;
        else m=a[s];
        return m;
    }
};