class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3)return res;
        sort(nums.begin(), nums.end());
        int l, r, sum;
        for(int i = 0; i < n - 2; i ++){
            l = i + 1;
            r = n - 1;
            // skip duplicate
            if(i && nums[i] == nums[i - 1])continue;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(!sum){
                    res.push_back({nums[i], nums[l], nums[r]});
                    // skip duplicate
                    while(l < r && nums[l + 1] == nums[l])l++;
                    while(l < r && nums[r] == nums[r - 1])r--;
                    l++, r--;
                }else if(sum > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return res;
    }
};