class Solution {
public:
   // #define ll long long
    #define MOD 1000000007
    int countOrders(int n) {
        vector<long long> dp(n);
        dp[0] = 1;
        for(int i=1; i<n; i++)
        {
            long long gaps = i*2 + 1;
            long long ways = (gaps * gaps) - (gaps * (gaps - 1))/2;
            
            dp[i] = (dp[i-1] * ways) % MOD;
        }
        return dp[n-1];
    }
};