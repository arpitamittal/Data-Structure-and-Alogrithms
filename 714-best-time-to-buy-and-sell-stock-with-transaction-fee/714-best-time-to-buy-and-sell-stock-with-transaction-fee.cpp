class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> vec(prices.size(), vector<int> (2,-1));
        return profit(prices, 0, 1, vec, fee);
    }
    int profit(vector<int> &prices, int currentDay, int canBuy, vector<vector<int>> &vec, int fee)
    {
        if(currentDay >= prices.size())
            return 0;
  
        if(vec[currentDay][canBuy] !=-1)
            return vec[currentDay][canBuy];
    
        if(canBuy == 1)
        {
            int idle = profit(prices, currentDay+1, canBuy, vec, fee);
            int buy = -prices[currentDay] + profit(prices, currentDay+1, 0, vec, fee);
            return vec[currentDay][canBuy] = max(idle, buy);
        }
        else
        { 
            int idle = profit(prices, currentDay+1, canBuy, vec, fee);
            int sell = -fee + prices[currentDay] + profit(prices, currentDay+1, 1, vec, fee);
            return vec[currentDay][canBuy] = max(idle, sell);
        }
    }
};