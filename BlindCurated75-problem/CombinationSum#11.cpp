class Solution {
public:
    void helper(vector<int>& cand, int target, int begin, vector<vector<int>>& res, vector<int>& comb){
        if(!target){
            res.push_back(comb);
            return;
        }
        for(int i = begin; i < cand.size() && cand[i] <= target; i++){
            comb.push_back(cand[i]);
            helper(cand, target - cand[i], i, res, comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        helper(candidates, target, 0, res, comb);
        return res;
    }
};