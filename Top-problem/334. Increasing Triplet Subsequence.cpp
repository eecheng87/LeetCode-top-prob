class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < one){
                one = nums[i];
            }else if(nums[i] < two && nums[i] > one){
                two = nums[i];
            }else{
                if(two < nums[i])
                    return true;
            }
        }
        return false;
    }
};