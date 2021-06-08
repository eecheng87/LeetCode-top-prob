class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        set<int> s;
        // O(n)
        for(int i = 0; i < nums.size(); i++){
            // O(1)
            s.insert(nums[i]);
        }
        // O(n)
        for(auto i:s){
            int x = i;
            if(s.count(x - 1) > 0)
                continue;
            while(s.count(x) != 0){
                x++;
            }
            res = max(res, x - i);
        }
        return res;
    }
};