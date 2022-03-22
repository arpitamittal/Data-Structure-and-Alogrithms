class Solution {
public:
    int rob(vector<int>& nums) {
      unordered_map<int, int> mp;
      return maxAmount (nums, 0, mp);  
    }
    int maxAmount(vector<int> &nums, int curr, unordered_map<int, int> &mp)
    {
        if(curr >= nums.size()) return 0;
        int currentKey = curr;
        if(mp.find(currentKey) != mp.end())
            return mp[curr];
        int yes_rob = nums[curr] + maxAmount(nums, curr+2, mp);
        int no_rob = maxAmount(nums, curr+1, mp);
        mp[curr] = max(yes_rob, no_rob);
        return mp[curr];
    }
};