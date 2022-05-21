class Solution {
public:
     int minCoins(int curridx, vector<int>& coins, int amount,vector<vector<int>>&dp){
        if (amount == 0) 
            return 0;
        if(curridx >= coins.size()) 
            return 100001;  
        
        if(dp[curridx][amount]!=-1) 
            return dp[curridx][amount];
        int consider = 100001;
        
        if(coins[curridx]<=amount)
            consider = 1 + minCoins(curridx,coins,amount-coins[curridx],dp);
        
        int notConsider = minCoins(curridx+1,coins,amount,dp);
        
        return dp[curridx][amount] = min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = minCoins(0, coins, amount, dp);
        return ans == 100001 ? -1 : ans; 
    }
};