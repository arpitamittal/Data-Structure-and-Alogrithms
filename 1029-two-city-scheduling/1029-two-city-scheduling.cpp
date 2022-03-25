class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size = costs.size(), ans = 0;
        vector<int> diff;
        
        for(int i=0; i<size; i++)
        {
            ans += costs[i][0];
            diff.push_back(costs[i][1] - costs[i][0]);
        }
        sort(diff.begin(), diff.end());
        for(int j=0; j<size/2; j++)  ans += diff[j];
        return ans;
    }
};