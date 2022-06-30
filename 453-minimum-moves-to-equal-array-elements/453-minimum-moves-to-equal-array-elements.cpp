class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int moves = 0;
        for(int i=0; i<size; i++)
            moves += abs(nums[0] - nums[i]);
        return moves;
    }
};