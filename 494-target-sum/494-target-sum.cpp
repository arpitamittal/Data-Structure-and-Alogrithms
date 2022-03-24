class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
       return totalWays(nums, 0, target, mp); 
    }
    int totalWays(vector<int>& nums, int current, int target, unordered_map<string, int> &mp)
    {
        if(current == nums.size() && target == 0)
            return 1;
         if(current == nums.size() && target != 0)
            return 0;
        
        string currentKey = to_string(current) + "-" + to_string(target);
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        
        int posSign = totalWays(nums, current+1, target - nums[current], mp);
        int negSign = totalWays(nums, current+1, target + nums[current], mp);
        mp[currentKey] = posSign + negSign;
        return mp[currentKey];
    }
};