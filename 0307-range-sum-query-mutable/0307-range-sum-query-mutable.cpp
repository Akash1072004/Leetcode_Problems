class NumArray {
public:
    vector<int>st;
    vector<int>v;
    void buildSegmentTree(int l, int h, int i){
        if(l == h){
            st[i] = v[l];
            return;
        }
        buildSegmentTree(l,(l+h)>>1,2*i+1);
        buildSegmentTree(((l+h)>>1) + 1,h,2*i+2);
        st[i] = st[2*i+1] + st[2*i+2];
    }
    int getSum(int left, int right, int i, int l, int h){
        if(right < l or left > h)return 0;
        if(l >= left and h <= right)return st[i];
        int mid = (l + h) >> 1;
        int leftSum = getSum(left,right,2*i+1,l,mid);
        int rightSum = getSum(left,right,2*i+2,mid+1,h);
        return leftSum + rightSum;
        
    }
    void updateVal(int i, int lo, int hi, int index, int val){
        if(lo == hi){
            st[i] = val;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(index <= mid) updateVal(2*i+1,lo,mid,index,val);
        else updateVal(2*i+2,mid+1,hi,index,val);
        st[i] = st[2*i+1] + st[2*i+2];
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        v = nums;
        st.resize(4*n);
        buildSegmentTree(0,n-1,0);
    }
    
    void update(int index, int val) {
        updateVal(0,0,v.size()-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return getSum(left,right,0,0,v.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */