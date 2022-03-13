class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int size = nums.size(), temp = 0;
        vector<int> ans;
       
        for(int i=0; i<size; i++)
        {
             for(int j=0; j<size; j++)
                {
                    if(abs(i-j) <= k && nums[j] == key)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
          }  
        return ans;
    }
};
