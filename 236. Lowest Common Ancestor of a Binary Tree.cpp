/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool helper(TreeNode* node, TreeNode* p, TreeNode* q){
        bool cur = false, a, b;
        if(!node)
            return false;
        if(node == p || node == q)
            cur = true;

        a = helper(node->left, p, q);
        b = helper(node->right, p, q);
        if(a && b){
            ans = node;
            return false;
        }
        if(a || b){
            if(cur){
                ans = node;
                return false;
            }else
                return true;
        }
        return cur ? true : false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};