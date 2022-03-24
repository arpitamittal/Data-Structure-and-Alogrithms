class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       return totalWays(nums, 0, target); 
    }
    int totalWays(vector<int>& nums, int current, int target)
    {
        if(current == nums.size() && target == 0)
            return 1;
         if(current == nums.size() && target != 0)
            return 0;
        
        int posSign = totalWays(nums, current+1, target - nums[current]);
        int negSign = totalWays(nums, current+1, target + nums[current]);
        return posSign + negSign;
    }
};