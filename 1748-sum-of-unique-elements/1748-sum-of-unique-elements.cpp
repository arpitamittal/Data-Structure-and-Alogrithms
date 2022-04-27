class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
       int ans = 0;
       unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]] += 1;
        for(auto it : mp)
        {
            if(it.second == 1)
                ans += it.first;
        }
        return ans;
    }
};