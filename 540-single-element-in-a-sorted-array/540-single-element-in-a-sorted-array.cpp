class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       int size = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++) mp[nums[i]]++;
        for(auto x : mp)
        {
            if(x.second == 1)
                return x.first;
        }
        return -1;
    }
};