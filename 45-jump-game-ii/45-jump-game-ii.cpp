class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> vec(nums.size()+1, -1);
       return minJumps(nums, 0, vec); 
    }
    int minJumps(vector<int> &nums, int current, vector<int> &vec)
    {
        if(current >= nums.size()-1)
            return 0;
        if(nums[current] == 0)
            return 100001;
        int currentJumps = nums[current];
        int ans = 100001;
        int currentKey = current;
        if(vec[currentKey] != -1)
            return vec[currentKey];
        for(int i=1; i<=currentJumps; i++)
        {
            int temp = 1 + minJumps(nums, current+i, vec);
            ans = min(ans, temp);
        }
        vec[currentKey] = ans;
        return vec[currentKey];
    }
};