// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int weight[], int profit[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int> (w+1, -1));
       return maxProfit(w, weight, 0, profit, n, dp);
    }
    int maxProfit(int capacity, int weight[], int curr, int profit[], int n, vector<vector<int>> &dp)
    {
        if(curr >= n) return 0;
        
        int currentItemWeight = weight[curr];
        int currentItemProfit = profit[curr];
        
        // string currentKey = to_string(curr) + "_" + to_string(capacity);
        
        // if(mp.find(currentKey) != mp.end())
        //     return mp[currentKey];
        if(dp[curr][capacity] != -1)
            return dp[curr][capacity];
            
        int consider = 0;
        if(capacity >= currentItemWeight)
           consider = currentItemProfit + maxProfit(capacity - currentItemWeight, weight, curr+1, profit, n, dp);
           
        int notConsider = maxProfit(capacity, weight, curr+1, profit, n, dp);
        
        dp[curr][capacity] = max(consider, notConsider);
        
        return dp[curr][capacity];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends