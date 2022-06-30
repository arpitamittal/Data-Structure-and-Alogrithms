class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int middle = nums[size/2];
        int moves = 0;
        for(int i=0; i<size; i++)
            moves += abs(nums[i] - middle);
        return moves;
    }
};