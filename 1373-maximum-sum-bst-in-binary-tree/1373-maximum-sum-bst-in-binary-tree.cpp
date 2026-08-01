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

    unordered_map<TreeNode*, int> isBST;
    unordered_map<TreeNode*, int> maxVal;
    unordered_map<TreeNode*, int> maxi;
    unordered_map<TreeNode*, int> mini;

    void f(TreeNode* root) {
        if(root == NULL) return;

        f(root->left);
        f(root->right);

        if(root->left == NULL && root->right == NULL) {
            maxi[root] = root->val;
            mini[root] = root->val;
            maxVal[root] = root->val;
            isBST[root] = 1;

            ans = max(ans, maxVal[root]);
            return;
        }

        maxi[root] = mini[root] = root->val;
        maxVal[root] = root->val;
        isBST[root] = 0;

        if(root->left != NULL && root->right != NULL) {

            if(isBST[root->left] && isBST[root->right] &&
               root->val > maxi[root->left] &&
               root->val < mini[root->right]) {

                isBST[root] = 1;

                maxVal[root] =
                    root->val +
                    maxVal[root->left] +
                    maxVal[root->right];

                mini[root] = mini[root->left];
                maxi[root] = maxi[root->right];

                ans = max(ans, maxVal[root]);
            }
        }
        else if(root->left != NULL) {

            if(isBST[root->left] &&
               root->val > maxi[root->left]) {

                isBST[root] = 1;

                maxVal[root] =
                    root->val +
                    maxVal[root->left];

                mini[root] = mini[root->left];
                maxi[root] = root->val;

                ans = max(ans, maxVal[root]);
            }
        }
        else {

            if(isBST[root->right] &&
               root->val < mini[root->right]) {

                isBST[root] = 1;

                maxVal[root] =
                    root->val +
                    maxVal[root->right];

                mini[root] = root->val;
                maxi[root] = maxi[root->right];

                ans = max(ans, maxVal[root]);
            }
        }
    }

    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};