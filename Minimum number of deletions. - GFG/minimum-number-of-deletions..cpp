// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

int dp[1001][1001];
int longest(string &str, int startIndex, int endIndex)
{
        int ans1=0, ans2=0;
        if(startIndex > endIndex)
            return dp[startIndex][endIndex] = 0;
        if(startIndex == endIndex)
            return dp[startIndex][endIndex] = 1;
        
        if(dp[startIndex][endIndex] != -1)
            return dp[startIndex][endIndex];
        if(str[startIndex] == str[endIndex])
            return dp[startIndex][endIndex] = 2 + longest(str, startIndex+1, endIndex-1);
        else
        {
            ans1 = longest(str, startIndex+1, endIndex);
            ans2 = longest(str, startIndex, endIndex-1);
        }
        dp[startIndex][endIndex] = max(ans1, ans2);
        return dp[startIndex][endIndex];
}
int minDeletions(string str, int n) { 
    //complete the function here 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
           dp[i][j] = -1;
    int len = longest(str, 0, n-1);
    return n - len;
} 
