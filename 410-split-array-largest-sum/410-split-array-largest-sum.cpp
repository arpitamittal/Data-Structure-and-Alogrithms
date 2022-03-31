class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxNo = 0, total = 0;
        for( int num : nums)
        {
            maxNo = max(num, maxNo);
            total += num; 
        }
        int low = maxNo, high = total;
        while(low < high)
        {
            int mid = (low + high)/2;
            if(validDivision(mid, nums, m))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
    int validDivision(int possibleSum, vector<int> &nums, int m)
    {
        int totalSubsetCount = 1, totalRemainingSum = 0;
        for(int num : nums)
        {
            totalRemainingSum += num;
            if(totalRemainingSum > possibleSum)
            {
                totalRemainingSum = 0;
                totalRemainingSum += num;
                totalSubsetCount++;
                if(totalSubsetCount > m)
                    return false;
            }
        }
        return true;
    }
};