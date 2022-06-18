// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int shortest(string &str1, string &str2, int n, int m, int i1, int i2, vector<vector<int>> &dp)
    {
        if(i1 == n)
          return m - i2;
        if(i2 == m)
          return n - i1;
        if(dp[i1][i2] != -1)
           return dp[i1][i2]; 
        if(str1[i1] == str2[i2])
          return 1 + shortest(str1, str2, n, m, i1+1, i2+1, dp);
        int len1 = 1 + shortest(str1, str2, n, m, i1+1, i2, dp);
        int len2 = 1 + shortest(str1, str2, n, m, i1, i2+1, dp);
        return dp[i1][i2] = min(len1, len2);
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string str1, string str2, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return shortest(str1, str2, m, n, 0, 0, dp);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends