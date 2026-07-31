class Solution {
public:
    int trap(vector<int>& v) {
        int x = v.size();
        stack<int>st;
        vector<int>ans(x);
        st.push(v[0]);
        ans[0]=-1;
        for(int i=1;i<x;i++){
            while(st.size()>0 && v[i]>=st.top())st.pop();
            if(st.size()==0){
                ans[i]=-1;
                st.push(v[i]);
            }
            else ans[i]=st.top();
        }
        stack<int>t;
        vector<int>ans2(x);
        t.push(v[x-1]);
        ans[x-1]=-1;
        for(int i=x-1;i>=0;i--){
            while(t.size()>0 && v[i]>=t.top())t.pop();
            if(t.size()==0){
                ans2[i]=-1;
                t.push(v[i]);
            }
            else ans2[i]=t.top();
        }
        int sum = 0;
        for(int i=0;i<x;i++){
            if(ans[i]==-1 || ans2[i]==-1)continue;
            ans[i]=min(ans[i],ans2[i])-v[i];
            sum+=ans[i];
        }
        return sum;

    }
};