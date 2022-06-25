class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                count++;
                if(i-2>=0 && i+1<nums.size() && nums[i-2]>nums[i] && nums[i-1]>nums[i+1]) return false;
            }
            
        }
        return count<=1;
    }
};