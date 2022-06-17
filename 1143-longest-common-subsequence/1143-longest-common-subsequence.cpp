class Solution {
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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findLCSLength(text1, text2, 0, 0, dp);
    }
};