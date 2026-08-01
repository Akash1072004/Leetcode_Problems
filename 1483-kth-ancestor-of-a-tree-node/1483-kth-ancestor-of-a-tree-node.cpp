class TreeAncestor {
public:
    vector<vector<int>> dp;
    int row, col;
    vector<int> parent;

    TreeAncestor(int n, vector<int>& parent) {
        this->parent = parent;
        row = n;
        col = log2(n)+1;
        dp.resize(n, vector<int>(col, -2));

        // for(int node = 0; node < n; node++) {
        //     ancestorTable[node][0] = parent[node];
        // }

        // for(int j = 1; j < col; j++) {                     
        //     for(int node = 0; node < n; node++) {
        //         if(ancestorTable[node][j-1] != -1) {
        //             ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
        //         }
        //     }
        // }
    }

    int f(int node, int j) {
        if(j == 0) return parent[node];

        if(dp[node][j] != -2) return dp[node][j];
        int mid = f(node, j-1);
        if(mid == -1) return dp[node][j] = -1;
        else return dp[node][j] = f(mid, j-1);
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < col; j++) {
            if(k & (1 << j)) {
                node = f(node, j); // take 2^j jump form this node

                if(node == -1) return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */