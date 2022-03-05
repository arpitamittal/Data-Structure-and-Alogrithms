class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10002];
        vector<int> freq(10002);
        for(auto i : nums) freq[i]++;
        
        dp[1] = freq[1]; 
        dp[2] = max(freq[1], 2*freq[2]);
        for(int i=3; i<10002; i++) dp[i] = max(dp[i-1], dp[i-2]+freq[i]*i);
        
        return dp[10001];
    }
};