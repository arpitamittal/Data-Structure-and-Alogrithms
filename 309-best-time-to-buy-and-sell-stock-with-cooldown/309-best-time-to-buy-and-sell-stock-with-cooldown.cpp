class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<string, int> mp;
        return profit(prices, 0, 1, mp);
    }
    int profit(vector<int> &prices, int currentDay, int canBuy, unordered_map<string, int> &mp)
    {
        if(currentDay >= prices.size())
            return 0;
        string currentKey = to_string(currentDay) + "-" + to_string(canBuy);
        
        if(mp.find(currentKey) != mp.end())
            return mp[currentKey];
        
        int ans = 0;
        if(canBuy == 1)
        {
            int idle = profit(prices, currentDay+1, canBuy, mp);
            int buy = -prices[currentDay] + profit(prices, currentDay+1, 0, mp);
            ans = max(idle, buy);
        }
        else
        { 
            int idle = profit(prices, currentDay+1, canBuy, mp);
            int sell = prices[currentDay] + profit(prices, currentDay+2, 1, mp);
            ans = max(idle, sell);
        }
        mp[currentKey] = ans;
        return ans;
    }
};