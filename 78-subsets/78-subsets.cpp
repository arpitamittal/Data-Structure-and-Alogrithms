class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int>temp;
        generateAllSubsets(nums, 0, temp, powerset);
        return powerset;
    }
    void generateAllSubsets(vector<int> &nums, int currentIndex, vector<int> &currentSubset, vector<vector<int>> &powerset)
    {
        if(currentIndex == nums.size())
        {
            powerset.push_back(currentSubset);
            return;
        }
 
        currentSubset.push_back(nums[currentIndex]);
        generateAllSubsets(nums,currentIndex+1,currentSubset,powerset);
        currentSubset.pop_back();
        generateAllSubsets(nums,currentIndex+1,currentSubset, powerset);
    }
};