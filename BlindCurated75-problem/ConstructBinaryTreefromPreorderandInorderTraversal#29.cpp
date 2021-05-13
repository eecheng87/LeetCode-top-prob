/* 
    explanation: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution 
*/
class Solution {
public:
    TreeNode* helper(int ins, int ine, int pres, vector<int>& preorder, vector<int>& inorder){
        if(ins > ine || pres > preorder.size() - 1)
            return NULL;
        int index;
        TreeNode* node = new TreeNode(preorder[pres]); 
        for(index = ins; index < ine; index++)
            if(inorder[index] == node->val)
                break;
        
        node->left = helper(ins, index - 1, pres + 1, preorder, inorder);
        node->right = helper(index + 1, ine, index - ins + pres + 1, preorder, inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, preorder.size() - 1, 0, preorder, inorder);
    }
};