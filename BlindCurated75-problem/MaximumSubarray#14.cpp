class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -1e6, cur = 0;
        for(auto i : nums){
            cur += i;
            res = max(res, cur);
            if(cur < 0)
                cur = 0;
        }
        return res;
    }
};