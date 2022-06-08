class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int> mp;
        int a =minCost(cost,0,mp);
        int b =minCost(cost,1,mp);
        return min(a,b);
    }
    int minCost(vector<int> &cost, int currIndex, unordered_map<int,int> &mp)
    {
        if(currIndex == cost.size())
            return 0;
        if(currIndex > cost.size())
            return 10000;
        if(mp.find(currIndex)!=mp.end())
            return mp[currIndex];
        int currKey = currIndex;
        int oneJump = cost[currKey] + minCost(cost, currKey+1, mp);
        int twoJump = cost[currKey] + minCost(cost, currKey+2, mp);         
        mp[currKey] = min(oneJump,twoJump);

        return min(oneJump,twoJump);

    }
};