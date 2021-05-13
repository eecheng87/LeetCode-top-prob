/* better solution: https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33443/C%2B%2B-solution-using-only-one-queue-use-a-marker-NULL */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int cur = 0;
        unsigned long long next_num_null = 0, cur_num_null = 0, limit = 1;
        vector<vector<int>> res;
        vector<int> li;
        queue<TreeNode*> q;
        if(!root)return res;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            li.push_back(tmp->val);
            q.pop();
            cur++;
            if(tmp->left)
                q.push(tmp->left);
            else
                next_num_null++;
            if(tmp->right)
                q.push(tmp->right);
            else
                next_num_null++; 
            if(cur == limit - cur_num_null){
                cur = 0;
                limit = limit << 1;
                cur_num_null = next_num_null;
                next_num_null = next_num_null << 1;
                res.push_back(li);
                li.clear();
            }
        }
        return res;
    }
};