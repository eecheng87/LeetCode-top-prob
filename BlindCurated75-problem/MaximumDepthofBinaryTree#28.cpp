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
    int res = 0;
    void helper(TreeNode* node, int cur){
        if(!node){
            res = max(cur, res);
            return;
        }
        helper(node->left, cur + 1);
        helper(node->right, cur + 1);
    }
    int maxDepth(TreeNode* root) {
        helper(root, 0);
        return res;
    }
};