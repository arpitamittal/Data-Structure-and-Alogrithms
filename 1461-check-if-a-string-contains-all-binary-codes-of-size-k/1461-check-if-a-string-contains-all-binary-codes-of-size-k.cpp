class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        int size = s.size();
        if(k > size) return false;
        unordered_set<string> store;
        string curr = "";
        for(int i=0; i<k; i++)
        {
            curr += s[i];
        }
        store.insert(curr);
        for(int i=k; i<size; i++)
        {
            curr.erase(curr.begin());
            curr += s[i];
            store.insert(curr);
        }
        return store.size() == (1<<k);
    }
};