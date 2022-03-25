class Solution {
public:
    int change(int amount, vector<int>& coins) {
             unordered_map<string,int> mp;
             return totalWays(coins, 0, amount, mp);
         }
    int totalWays(vector<int> &coins, int current, int amount, unordered_map<string, int> &mp)
    {
        if(amount == 0) return 1;
        if(current >= coins.size()) return 0;
        int consider = 0;
        string currentKey = to_string(current) +"-" + to_string(amount);
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        if(coins[current] <=amount)
            consider = totalWays(coins, current, amount - coins[current], mp);
        int notConsider = totalWays(coins, current+1, amount, mp);
        mp[currentKey] = consider + notConsider;
        return mp[currentKey];
    }

};