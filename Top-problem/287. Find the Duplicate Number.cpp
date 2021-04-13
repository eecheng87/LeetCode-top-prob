// Solution 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            if(myset.count(nums[i]) != 0)
                return nums[i];
            else
                myset.insert(nums[i]);
        }
        return 0;
    }
};

// Solution 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtle = nums[0];
        int hare = nums[0];

        // phase 1
        do{
            turtle = nums[turtle];
            hare = nums[nums[hare]];
        }while(turtle != hare);

        // phase 2
        turtle = nums[0];
        while(turtle != hare){
            turtle = nums[turtle];
            hare = nums[hare];
        }
        return hare;
    }
};