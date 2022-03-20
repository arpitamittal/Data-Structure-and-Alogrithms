class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> pq;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        double target = sum/2;
        int count = 0;
        while(sum > target)
        {
            count++;
            double highest = pq.top();
            pq.pop();
            sum -= highest;
            highest = highest/2;
            sum += highest;
            pq.push(highest);
        }
        return count;
    }
};