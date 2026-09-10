/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int count(TreeNode* root) {
        if(root == NULL) return 0;
        return count(root->left) + count(root->right) + 1;
    }
    int f(TreeNode* root) {
        if(root == NULL) return 0;
        int left = f(root->left);
        int right = f(root->right);

        int sum = left + right + root->val;
        int node = count(root);
        if(sum/node == root->val) ans++;
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        
        f(root);
        return ans;
        

    }
};