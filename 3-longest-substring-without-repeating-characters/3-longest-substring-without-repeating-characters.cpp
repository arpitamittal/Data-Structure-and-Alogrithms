class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer=0,left=0,maxLen=0, size=s.size();
        unordered_map<char,int> mp;
        for(int i=0; i<size; i++)
        {
            if(mp.find(s[i])==mp.end()) mp[s[i]]=i;
            else
            {
                left=max(left, mp[s[i]]+1);
                mp[s[i]]=i;
            }
            maxLen=max(maxLen, i-left+1);
        }
        return maxLen;
    }
};