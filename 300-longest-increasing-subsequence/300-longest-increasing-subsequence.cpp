class Solution {
public:
    int findLength(vector<int>& nums, int current, int prev, vector<vector<int>> &dp)
    {
        if(current == nums.size())
            return 0;
        int count1 = 0;
        if(dp[current][prev+1] != -1)
            return dp[current][prev+1];
        if(prev == -1 || nums[current] > nums[prev])
            count1 = 1 + findLength(nums, current+1, current, dp);
        int count2 = findLength(nums, current+1, prev, dp);
        return dp[current][prev+1] = max(count1, count2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return findLength(nums, 0, -1, dp);
    }
};