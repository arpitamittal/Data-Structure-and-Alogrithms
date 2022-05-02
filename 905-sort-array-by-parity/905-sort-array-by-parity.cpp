class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int> v1, v2;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] %2 == 0) v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        }
        
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};