class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int size=nums.size();
        if(size==0)
            return 0;
        sort(nums.begin(),nums.end());
        int ans=1,curr=1,pre=nums[0];
        for(int i=0;i<size;i++)
        {
            if(nums[i]==pre+1)
                curr++;
            else if(nums[i]!=pre) 
                curr=1;
            pre=nums[i];
            ans=max(curr,ans);
        }
      return ans;
        
    }
};