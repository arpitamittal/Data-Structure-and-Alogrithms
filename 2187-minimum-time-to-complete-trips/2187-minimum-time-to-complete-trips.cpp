class Solution {
public:
    long long trips(vector<int> &time, long long sec)
    {
        long long count = 0;
        for(auto it : time) count += (sec/it);
        return count;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e14;
        long long ans = high;
        while(low <= high)
        {
            long long mid = (low + high) / 2;
            if(trips(time, mid) >= totalTrips)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};