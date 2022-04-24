class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0 ) return {-1, -1};
        int last = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() ;
        last--;
        if(last < 0 || target != nums[last]) return {-1, -1 };
       // cout<<last <<" ";
        int first = upper_bound(nums.begin(), nums.end(), target - 1) - nums.begin();        
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
 
 
 lower ,  target +1 ->
 lower , target - 1 
 upper , traget - 1
 upper , target +1 
*/