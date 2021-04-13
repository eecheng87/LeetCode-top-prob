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
    int cnt = 0;
    void helper(TreeNode* node){
        if(node->left)
            helper(node->left);
        cnt--;
        if(cnt == 0){
            ans = node->val;
            return;
        }
        if(node->right)
            helper(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        helper(root);
        return ans;
    }
};