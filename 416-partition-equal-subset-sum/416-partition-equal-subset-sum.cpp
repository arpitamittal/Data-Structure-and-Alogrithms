class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;
        if(totalSum % 2 != 0) 
            return false;
        vector<vector<int>> dp(nums.size(), vector<int>((totalSum/2)+1, -1));
        return isPossible(nums, totalSum/2, 0, dp);
    }
    int isPossible(vector<int> &nums, int target, int currentIndex, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        if(currentIndex >= nums.size())
            return false;
        if(dp[currentIndex][target] != -1)
            return dp[currentIndex][target];
        bool consider = false;
        if(nums[currentIndex] <= target)
            consider = isPossible(nums, target - nums[currentIndex], currentIndex+1, dp);
        if(consider)
        {
            dp[currentIndex][target] = consider;
            return true;
        }
        int notConsider = isPossible(nums, target, currentIndex+1, dp);
        dp[currentIndex][target] = consider || notConsider;
        return dp[currentIndex][target];
    }
};