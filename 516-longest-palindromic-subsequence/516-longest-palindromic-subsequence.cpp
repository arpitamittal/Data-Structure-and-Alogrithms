class Solution {
public:
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
    int longestPalindromeSubseq(string s) 
    {
        int size = s.size();
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                dp[i][j] = -1;
        return longest(s, 0, size-1);
    }
};