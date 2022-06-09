class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size();
        
        int start=0,end=size-1;
        while(start<end)
        {
            int sum = numbers[start] + numbers[end];
            if(sum == target) return {start+1, end+1};
            else if (sum>target) end--;
            else start++;
        }
        
        return {-1,-1};
    }
};