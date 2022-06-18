// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int findLCSLength(string &str1, string &str2, int i1, int i2, vector<vector<int>> &dp)
    {
        if(i1 == str1.size() || i2 == str2.size())
            return 0;
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        if(str1[i1] == str2[i2])
            return dp[i1][i2] = 1 + findLCSLength(str1, str2, i1+1, i2+1, dp);
        int z1 = findLCSLength(str1, str2, i1+1, i2, dp);
        int z2 = findLCSLength(str1, str2, i1, i2+1, dp);
        return dp[i1][i2] = max(z1, z2);
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return n + m - 2 * (findLCSLength(str1, str2, 0, 0, dp));
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends