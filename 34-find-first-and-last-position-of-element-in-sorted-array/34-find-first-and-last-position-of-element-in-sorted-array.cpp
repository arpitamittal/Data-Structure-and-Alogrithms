class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = -1, right = -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == target)
            {
                if(left == -1)  left = i;
                right = i;         
            }
        }
        return {left, right};
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
 
 i=0  
 
left = 0, rigt
*/