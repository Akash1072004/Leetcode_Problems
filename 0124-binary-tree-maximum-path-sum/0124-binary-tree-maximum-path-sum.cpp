class Solution {
public:
    int ans = INT_MIN;
    int f(TreeNode* root){
        if(root == NULL)return 0; 
        int l = max(0,f(root->left));
        int r = max(0,f(root->right));
        int v = root->val;
        ans = max(ans,l+r+v);
        return max({r+v,l+v});
    }

    int maxPathSum(TreeNode* root) {
        if(root->left == NULL and root->right == NULL)return root->val;
        f(root);
        return ans;
    }
};
