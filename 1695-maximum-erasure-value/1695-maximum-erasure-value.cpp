class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int maxi=INT_MIN;
        int i=0,j=0;
        int sum=0;
        while(i<nums.size())
        {
           while(j<i && mp[nums[i]] !=0 )
           {
               mp[nums[j]]=0;
               sum-=nums[j++];
           }
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]=1;
                sum+=nums[i++];
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};