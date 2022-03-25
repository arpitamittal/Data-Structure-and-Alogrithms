class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(100001);
        int maxi = 0;
        unordered_map<int, int> mp;
        for(auto num : nums)
        {
            freq[num]++;
            maxi = max(maxi, num);
        }
        return points(freq, 0, maxi, mp);
    }
    int points( vector<int> &freq, int current, int maxi, unordered_map<int, int> &mp)
    {
        if(current > maxi)
            return 0;
        int currentKey = current;
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        int earn = freq[current]*current + points(freq, current+2, maxi, mp);
        int skip = points(freq, current+1, maxi, mp);
        mp[currentKey] = max(earn, skip);
        return mp[currentKey];
    }
};