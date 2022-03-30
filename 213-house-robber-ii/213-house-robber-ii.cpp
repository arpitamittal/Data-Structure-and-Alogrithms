class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        unordered_map<int, int> mp1, mp2;
        return max(maxAmount(0, nums.size()-1, nums, mp1), maxAmount(1, nums.size(), nums, mp2));
    }
    int maxAmount(int current, int end, vector<int> &nums, unordered_map<int, int> &mp)
    {
        if(current >= end)
            return 0;
        if(mp.find(current) != mp.end())
            return mp[current];
        int pick = nums[current] + maxAmount(current+2, end, nums, mp);
        int notPick = maxAmount(current+1, end, nums, mp);
        mp[current] = max(pick, notPick);
        return mp[current];
    }
};