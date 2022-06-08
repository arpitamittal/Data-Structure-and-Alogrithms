// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
/*
int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>((W+1),-1));
        //unordered_map<string, int> mp;
        maxProfit(n, W, 0, val, wt, dp);
    }
    int maxProfit(int size, int capacity, int current, int profit[], int weight[], vector<vector<int>> &dp)
    {
        if(current >= size) return 0;
        if(capacity == 0) return 0;
        
        int currentItemWeight = weight[current];
        int currentItemProfit = profit[current];
        int consider = 0, notConsider = 0;
        // string currentKey = to_string(current) + "-" + to_string(capacity);
        // if(mp.find(currentKey) != mp.end())
        //   return mp[currentKey];
        if(dp[current][capacity ] != -1)
           return dp[current][capacity];
        if(currentItemWeight <= capacity)
           consider = currentItemProfit + maxProfit(size, capacity - currentItemWeight, current, profit, weight, mp);
        notConsider = maxProfit(size, capacity, current+1, profit, weight, mp);
        // mp[currentKey] = max(consider, notConsider);
        // return mp[currentKey];
        dp[current][capacity] = max(consider, notConsider);
        return dp[current][capacity];
    }
*/
class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>((W+1),-1));
        return maxProfit(n, W, 0, val, wt, dp);
    }
    int maxProfit(int size, int capacity, int current, int profit[], int weight[], vector<vector<int>> &dp)
    {
        if(current >= size || capacity <= 0) return 0;
        //if(capacity == 0) return 0;
        
        int currentItemWeight = weight[current];
        int currentItemProfit = profit[current];
        int consider= 0, notConsider = 0;
       
        if(dp[current][capacity] != -1)
           return dp[current][capacity];
        if(currentItemWeight <= capacity)
           consider = currentItemProfit + maxProfit(size, capacity - currentItemWeight, current, profit, weight, dp);
        notConsider = maxProfit(size, capacity, current+1, profit, weight, dp);
       
        dp[current][capacity] = max(consider, notConsider);
        return dp[current][capacity];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends