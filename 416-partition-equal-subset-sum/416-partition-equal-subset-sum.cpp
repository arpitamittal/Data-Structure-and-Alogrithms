class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;
        if(totalSum % 2 != 0) 
            return false;
        unordered_map<string, bool> mp;
        return isPossible(nums, totalSum/2, 0, mp);
    }
    int isPossible(vector<int> &nums, int target, int currentIndex, unordered_map<string, bool> &mp)
    {
        if(target == 0)
            return true;
        if(currentIndex >= nums.size())
            return false;
        string currentKey = to_string(target) + " " + to_string(currentIndex);
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        bool consider = false;
        if(nums[currentIndex] <= target)
            consider = isPossible(nums, target - nums[currentIndex], currentIndex+1, mp);
        if(consider)
        {
            mp[currentKey] = consider;
            return true;
        }
        int notConsider = isPossible(nums, target, currentIndex+1, mp);
        mp[currentKey] = consider || notConsider;
        return mp[currentKey];
    }
};