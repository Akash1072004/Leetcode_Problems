class Solution {
public:
    #define ll long long
    vector<ll>sumSeg,sqSumSeg,lazySeg;
    void lazyAdd(int i,int l,int r,int val){
        int len = (r-l+1);
        sqSumSeg[i] += 2*val*sumSeg[i] + len*val*val;
        sumSeg[i] += len*val;
    }
    void updateRange(int start,int end,int i,int l,int r,int val){
        if(lazySeg[i]!= 0){
            lazyAdd(i,l,r,lazySeg[i]);
            if(l != r){
                lazySeg[2*i + 1] += lazySeg[i];
                lazySeg[2*i + 2] += lazySeg[i];
            }
            lazySeg[i]  = 0;
        }
        if( l > end || r < start || l > r)return;
        if(l >= start and r <= end){
            lazyAdd(i,l,r,val);
            if(l != r){
                lazySeg[2*i + 1] += val;
                lazySeg[2*i + 2] += val;
            }
            return ;
        }
        int mid = l + (r-l)/2;
        updateRange(start,end,2*i + 1,l,mid,val);
        updateRange(start,end,2*i + 2,mid+1,r,val);
        sumSeg[i] = sumSeg[2*i+1] + sumSeg[2*i+2];
        sqSumSeg[i] = sqSumSeg[2*i+1] + sqSumSeg[2*i+2];
    }
    int sumCounts(vector<int>& nums) {
        ll n = nums.size();
        sumSeg.assign(4*n,0);
        sqSumSeg.assign(4*n,0);
        lazySeg.assign(4*n,0);
        ll ans = 0;
        ll mod = 1e9 + 7;
        vector<int>lastSeen(1e5+1,-1);
        for(int i = 0;i<n;i++){
            int start = lastSeen[nums[i]]+1;
            int end = i;
            updateRange(start,end,0,0,n-1,1);
            ans = (ans + sqSumSeg[0])%mod;
            lastSeen[nums[i]] = i;
        }
        return ans;
    }
};