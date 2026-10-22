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
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left!=NULL){
                // save Right...
                TreeNode* r = cur->right;
                cur->right=cur->left;
                //Find the Predecessor...
                TreeNode* pre = cur->left;
                while(pre->right!=NULL)pre=pre->right;
                //Link...
                pre->right=r;
                cur=cur->left;
            }
            else cur=cur->right;
        }
        TreeNode* temp = root;
        while(temp){
            temp->left=NULL;
            temp=temp->right;
        }

    }
};