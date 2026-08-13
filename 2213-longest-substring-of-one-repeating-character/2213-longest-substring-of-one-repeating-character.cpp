class SegmentTree {
public:
    struct Node {
        int len;
        char left, right;
        int pref, suff, best;

        Node() {
            len = 0;
            left = right = '#';
            pref = suff = best = 0;
        }

        Node(char c) {
            len = 1;
            left = right = c;
            pref = suff = best = 1;
        }
    };

    vector<Node> tree;
    string s;
    int n;

    SegmentTree(string &str) {
        s = str;
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    Node merge(Node L, Node R) {
        if(L.len == 0) return R;
        if(R.len == 0) return L;

        Node res;

        res.len = L.len + R.len;
        res.left = L.left;
        res.right = R.right;
        res.pref = L.pref;

        if(L.pref == L.len && L.right == R.left) {
            res.pref = L.len + R.pref;
        }
        res.suff = R.suff;

        if(R.suff == R.len && L.right == R.left) {
            res.suff = R.len + L.suff;
        }
        res.best = max(L.best, R.best);
        if(L.right == R.left) {
            res.best = max(res.best, L.suff + R.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if(l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if(l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) update(node * 2, l, mid, idx, c);
        else update(node * 2 + 1, mid + 1, r, idx, c);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, char c) {
        update(1, 0, n - 1, idx, c);
    }

    int getBest() {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        
        SegmentTree st(s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getBest());
        }

        return ans;

    }
};