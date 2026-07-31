class SegmentTree {
private:
    int n;
    vector<int> a;
    vector<int> tree;

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int queryTree(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) >> 1;
        int ans = 0;

        if (ql <= mid) {
            ans = max(ans, queryTree(node << 1, l, mid, ql, qr));
        }
        if (qr > mid) {
            ans = max(ans, queryTree(node << 1 | 1, mid + 1, r, ql, qr));
        }

        return ans;
    }

public:
    SegmentTree(const vector<int>& v) {
        a = v;
        n = a.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return queryTree(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<int> len, left, right;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) i++;
            if (s[st] == '0') {
                len.push_back(i - st);
                left.push_back(st);
                right.push_back(i - 1);
            }
        }

        int m = len.size();

        if (m < 2) {
            return vector<int>(queries.size(), ones);
        }

        vector<int> sum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            sum[i] = len[i] + len[i + 1];
        }

        SegmentTree st(sum);
        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int x = lower_bound(right.begin(), right.end(), l) - right.begin();
            int y = upper_bound(left.begin(), left.end(), r) - left.begin() - 1;

            if (x > m - 1 || y < 0 || x >= y) {
                ans.push_back(ones);
                continue;
            }

            int first = right[x] - max(left[x], l) + 1;
            int last = min(right[y], r) - left[y] + 1;

            if (x + 1 == y) {
                ans.push_back(ones + first + last);
                continue;
            }

            int a = first + len[x + 1];
            int b = len[y - 1] + last;
            int c = st.query(x + 1, y - 2);

            ans.push_back(ones + max({a, b, c}));
        }

        return ans;
    }
};