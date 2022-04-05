class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //unordered_map<string, int> mp;
        vector<vector<vector<int>>> vec(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(prices, 0, 1, 2, vec);
    }
    int profit(vector<int> &prices, int currentDay, int canBuy, int transCount, vector<vector<vector<int>>> &vec)
    {
        if(currentDay >= prices.size() || transCount == 0)
            return 0;
//         string currentKey = to_string(currentDay) + "-" + to_string(canBuy) + "-" + to_string(transCount);
        
//         if(mp.find(currentKey) != mp.end())
//             return mp[currentKey];
        if(vec[currentDay][canBuy][transCount] != -1)
           return vec[currentDay][canBuy][transCount]; 
        
        int ans = 0;
        if(canBuy == 1)
        {
            int idle = profit(prices, currentDay+1, canBuy, transCount, vec);
            int buy = -prices[currentDay] + profit(prices, currentDay+1, 0, transCount, vec);
            return vec[currentDay][canBuy][transCount] = max(idle, buy);
        }
        else
        { 
            int idle = profit(prices, currentDay+1, canBuy, transCount, vec);
            int sell = prices[currentDay] + profit(prices, currentDay+1, 1, transCount-1, vec);
            return vec[currentDay][canBuy][transCount] = max(idle, sell);
        }
        // mp[currentKey] = ans;
        // return ans;
    }
};