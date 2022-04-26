class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        multiset<int> mp;
        for(auto &n : nums) mp.insert(n);
        for(auto it : mp) 
        {
            if(mp.count(it) == 1)
                ans += it;
        }
        return ans;
    }
};