class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        bool ans;
        for(int i=0; i<size; i++)
        {
            if(nums[i] == target)
            {
                ans = true;
                return ans;
            }
        }
        return false;
    }
};