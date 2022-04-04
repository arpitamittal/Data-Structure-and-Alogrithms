class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        unordered_map<string, int> mp;
        return profit(prices, 0, 1, k, mp);
    }
    int profit(vector<int> &prices, int currentDay, int canBuy, int transCount, unordered_map<string, int> &mp)
    {
        if(currentDay >= prices.size() || transCount == 0)
            return 0;
        string currentKey = to_string(currentDay) + "-" + to_string(canBuy) + "-" + to_string(transCount);
        
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        
        int ans = 0;
        if(canBuy == 1)
        {
            int idle = profit(prices, currentDay+1, canBuy, transCount, mp);
            int buy = -prices[currentDay] + profit(prices, currentDay+1, 0, transCount, mp);
            ans = max(idle, buy);
        }
        else
        { 
            int idle = profit(prices, currentDay+1, canBuy, transCount, mp);
            int sell = prices[currentDay] + profit(prices, currentDay+1, 1, transCount-1, mp);
            ans = max(idle, sell);
        }
        mp[currentKey] = ans;
        return ans;
    }
};