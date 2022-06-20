class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        unordered_set<string> s(words.begin(), words.end());
        for(auto it : s)
        {
            for(int i=1; i<it.size(); i++)
                s.erase(it.substr(i));
        }
        int res = 0;
        for(string it : s) res += it.size() + 1;
        return res;
    }
};