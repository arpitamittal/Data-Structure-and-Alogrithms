class Solution {
public:
    int fib(int n) {
        unordered_map<int,int>mp;
        return nFib(n,mp);
    }
    int nFib(int num, unordered_map<int,int> &mp)
    {
        if(num == 0) return 0;
        if(num == 1) return 1;
        
        int currentkey = num;
        if(mp.find(currentkey) != mp.end())
            return mp[num];
        
        int a = nFib(num-1, mp);
        int b = nFib(num-2, mp);
        mp[num] = a+b;
        return mp[num];
    }
};