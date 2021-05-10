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
    bool helper(TreeNode* node, TreeNode* upper, TreeNode* lower){
        if(!node)return true;
        if((upper && node->val >= upper->val) || (lower && node->val <= lower->val))
            return false;
        return helper(node->left, node, lower) && helper(node->right, upper, node);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return helper(root, NULL, NULL);
    }
};