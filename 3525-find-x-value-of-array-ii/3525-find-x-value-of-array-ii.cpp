class Solution {
public:
    #define ll long long

    struct Node {
        int prod;
        ll cnt[5];

        Node() {
            prod = 1;
            for(int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int n, k;
    int sz;
    vector<Node> seg;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        res.prod = (1LL * a.prod * b.prod) % k;

        for(int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i];
        }

        for(int i = 0; i < k; i++) {
            if(b.cnt[i] == 0) continue;

            int x = (1LL * a.prod * i) % k;
            res.cnt[x] += b.cnt[i];
        }

        return res;
    }

    void update(int p, int val) {
        p += sz;

        seg[p] = Node();

        val %= k;

        seg[p].prod = val;
        seg[p].cnt[val] = 1;

        p >>= 1;

        while(p) {
            seg[p] = mergeNode(seg[p << 1], seg[p << 1 | 1]);
            p >>= 1;
        }
    }

    Node query(int l, int r) {
        Node a, b;

        l += sz;
        r += sz;

        while(l < r) {
            if(l & 1) {
                a = mergeNode(a, seg[l]);
                l++;
            }

            if(r & 1) {
                r--;
                b = mergeNode(seg[r], b);
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNode(a, b);
    }

    vector<int> resultArray(vector<int>& nums, int K, vector<vector<int>>& queries) {

        n = nums.size();
        k = K;

        sz = 1;

        while(sz < n) {
            sz <<= 1;
        }

        seg.resize(2 * sz);

        for(int i = 0; i < n; i++) {
            int x = nums[i] % k;

            seg[sz + i].prod = x;
            seg[sz + i].cnt[x] = 1;
        }

        for(int i = sz - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[i << 1], seg[i << 1 | 1]);
        }

        vector<int> ans;

        for(auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node res = query(start, n);

            ans.push_back(res.cnt[x]);
        }

        return ans;

        
    }
};