class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1, count = 0;
        while(left <= right)
        {
            int total_weight = people[left] + people[right];
            if(total_weight <= limit)
            {
                left++;
                right--;
            }
            else
                right--;
            count++;
        }
        return count;
    }
};