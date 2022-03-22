class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> mp;
        return nTribonacci(n, mp);
    }
    int nTribonacci(int n, unordered_map<int, int> &mp)
    {
        if(n==0 || n==1) return n;
        if(n == 2) return 1;
        
        int currentKey = n;
        if(mp.find(currentKey) != mp.end())
            return mp[n];
        mp[n] = nTribonacci(n-1, mp) + nTribonacci(n-2, mp) + nTribonacci(n-3, mp);
        
        return mp[n];
    }
};