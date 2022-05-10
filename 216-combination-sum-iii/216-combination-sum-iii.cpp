class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
        vector<int> temp;
        generateCombinations(1, k, n, temp, ans);
        return ans;
    }
    void generateCombinations(int curr, int currIndex, int target, vector<int>& temp, vector<vector<int>> &ans)
    {
        if(currIndex == temp.size() && target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(curr >= 10)
            return;
        generateCombinations(curr+1, currIndex, target, temp, ans);
        temp.push_back(curr);
        generateCombinations(curr+1, currIndex, target-curr, temp, ans);
        temp.pop_back();
    }
};