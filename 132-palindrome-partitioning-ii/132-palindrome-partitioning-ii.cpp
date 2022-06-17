class Solution {
public:
    bool isPalindrome(int start, int end, string &str)
    {
        while(start < end)
        {
            if(str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    int cuts(int current, int end, string &str, vector<int> &dp)
    {
        if(current == end)
            return 0;
        if(dp[current] != -1)
            return dp[current];
        int minCost = INT_MAX, cost = INT_MAX;
        for(int j=current; j<end; j++)
        {
            if(isPalindrome(current, j, str))
                cost = 1 + cuts(j+1, end, str, dp);
                minCost = min(cost, minCost);
        }
        return dp[current] = minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return cuts(0, n, s, dp) - 1;
    }
};