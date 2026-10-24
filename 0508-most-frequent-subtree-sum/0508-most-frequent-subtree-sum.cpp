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
    unordered_map<int, int> mp;
    int maxi = 0;
    int f(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = f(root->left);
        int right = f(root->right);

        int sum = root->val + left + right;
        mp[sum]++;
        maxi = max(maxi, mp[sum]);
        
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {

        f(root);

        vector<int> ans;

        for (auto it : mp) {
            if (it.second == maxi) {
                ans.push_back(it.first);
            }
        }

        return ans;


    }
};