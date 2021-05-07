/* Good explanation about binary search:
    https://blog.csdn.net/xushiyu1996818/article/details/102482609
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[l] <= nums[mid]){
                /* left part is in order */
                if(target >= nums[l] && target < nums[mid]){
                    /* target is in left part */
                    r = mid - 1;
                }else{
                    /* target is in right part */
                    l = mid + 1;
                }
            }else{
                /* right part is in order */
                if(target <= nums[r] && target > nums[mid]){
                    /* target is in right part */
                    l = mid + 1;
                }else{
                    /* target is in left part */
                    r = mid - 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};