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
    int res = -10e6;
    int helper(TreeNode* node){
        if(!node)
            return 0;
        int l = max(0, helper(node->left));
        int r = max(0, helper(node->right));
        res = max(res, l + r + node->val);
        return max(l, r) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        res = max(res, helper(root));
        return res;
    }
};