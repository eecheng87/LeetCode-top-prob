class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int med = (nums.size() + 1) /2;
        int n = nums.size();
        vector<int> cpy(nums);
        sort(cpy.begin(), cpy.end());
        
        int i, j;
        for(i = 0, j = med - 1; j >= 0; j--, i+=2)
            nums[i] = cpy[j];
        for(i = 1, j = n - 1; j >= med; j--, i+=2)
            nums[i] = cpy[j];
    }
};