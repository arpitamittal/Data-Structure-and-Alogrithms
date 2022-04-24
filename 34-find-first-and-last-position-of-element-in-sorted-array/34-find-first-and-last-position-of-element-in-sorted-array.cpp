class Solution {
public:
    int firstOccurence(vector<int> &nums, int start, int end, int target)
    {
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                end = mid - 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
    int lastOccurence(vector<int> &nums, int start, int end, int target)
    {
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                start = mid + 1;
            }
            else if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int first = firstOccurence(nums, 0, size-1, target); 
        if(first == -1) 
            return {-1,-1};
        int last = lastOccurence(nums, 0, size - 1, target);
        return {first, last};
    }
};
/*
    
 i=0  -> 5 != target
 i=1  ->  7 != target
 i=2   -> 7 !=target
 i=3   -> 8 == target    -> left = 3
 i=4   -> 9 == target   ->  right =  
 [2,5,13,]
 non - decreasing -> increasing order (non strictly increasing)
 
 
*/