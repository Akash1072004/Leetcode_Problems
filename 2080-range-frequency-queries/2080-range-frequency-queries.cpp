class RangeFreqQuery {
public:
    vector<int>v;
    vector<unordered_map<int,int>>st;
    unordered_map<int,int> addMap(unordered_map<int,int>&mp1,unordered_map<int,int>&mp2){
        unordered_map<int,int>mp;
        for(auto ele : mp2){
            int key = ele.first;
            int val = ele.second;
            mp.insert({key,val});
        }
        for(auto ele : mp1){
            int key = ele.first;
            int val = ele.second;
            if(mp.find(key) != mp.end()){
                mp[key] += val;
            }
            else mp[key] = val;
        }
        return mp;
    }
    void f(int l, int h, int i){
        if(l == h){
            st[i][v[l]] = 1; // st[i].insert({v[l],1}) ... these are the two types of filling in map;
            return;
        }
        int mid = (l+h) >> 1;
        f(l,mid,2*i+1);
        f(mid+1,h,2*i+2);
        st[i] = addMap(st[2*i+1], st[2*i+2]);
    }
    int freq(int left, int right, int l, int h, int i, int value){
        if(h < left or right < l)return 0;
        if(left <= l and right >= h) return st[i][value];
        int mid = (l+h)>>1;
        int leftFreq = freq(left,right,l,mid,2*i+1,value);
        int rightFreq = freq(left,right,mid+1,h,2*i+2,value);
        return leftFreq + rightFreq;
    }
    RangeFreqQuery(vector<int>& arr) {
        v = arr;
        int n = v.size();
        st.resize(4*n);
        f(0,v.size()-1,0);
    }
    
    int query(int left, int right, int value) {
        return freq(left,right,0,v.size()-1,0,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */