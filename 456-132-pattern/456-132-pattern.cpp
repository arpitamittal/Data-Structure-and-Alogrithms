class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third = INT_MIN, size = nums.size();
        for(int i=size-1; i>=0; i--)
        {
            if(nums[i] < third)
                return true;
            else
            {
                while(!st.empty() && nums[i] > st.top())
                {
                    third = st.top();
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
};