// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        return isPossible(arr, sum, 0, dp);
        
    }
    bool isPossible(vector<int> &arr, int target, int current, vector<vector<int>> &dp)
    {
        if(target == 0)
          return true;
        if(current >= arr.size())
           return false;
        if(dp[current][target] != -1)
           return dp[current][target];
        bool consider = false;
        if(arr[current] <= target)
           consider = isPossible(arr, target - arr[current], current+1, dp);
        if(consider)
        {
            dp[current][target] = consider;
            return true;
        }
        bool notConsider = isPossible(arr, target, current+1, dp);
        dp[current][target] = consider || notConsider;
        return dp[current][target];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends