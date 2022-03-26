class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size(), start = 0, end = size-1, mid;
        while(start <= end)
        {
            mid = (start + end) /2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                start = mid+1;
            else 
                end = mid-1;
        }
        return -1;
    }
};