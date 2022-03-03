class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size(), ans = 0, count = 0;
        if(size <= 2) return 0;
        for(int i=1; i<size-1; i++)
        {
            if(nums[i] - nums[i-1] == nums[i+1] - nums[i]) ans++;
            else ans = 0;    
            count += ans;   
        }
            return count;
    }
};