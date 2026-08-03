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
    void path(TreeNode* root,int targetSum,vector<int>v,vector<vector<int>>&ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }
        v.push_back(root->val);
        path(root->left,targetSum-root->val,v,ans);
        path(root->right,targetSum-root->val,v,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        path(root,targetSum,v,ans);
        return ans;

    }
};