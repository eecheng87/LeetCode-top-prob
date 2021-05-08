class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            cur = max(--cur, nums[i]);
            if(!cur)
                return false;
        }
        return true;
    }
};