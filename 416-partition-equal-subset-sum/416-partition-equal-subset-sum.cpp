class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        
        for(auto num : nums)
            totalSum += num;
        
        if(totalSum % 2 != 0)
            return false;
        unordered_map<string, bool> mp;
        return isPossible(nums, 0, totalSum/2, mp);
    }
    
    int isPossible(vector<int> &nums, int current, int target, unordered_map<string, bool> &mp)
    {
        if(target == 0)
            return true;
        if(current >= nums.size())
            return false;
        string currentKey = to_string(current) + to_string(target);
        
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        
        bool consider = false;  
        if(nums[current] <= target)
            consider = isPossible(nums, current+1, target - nums[current], mp);
        
        if(consider)
        {
            mp[currentKey] = consider;
            return true;
        }
        
        int notConsider = isPossible(nums, current+1, target, mp);
        mp[currentKey] = consider || notConsider;
        return mp[currentKey];
    }
};