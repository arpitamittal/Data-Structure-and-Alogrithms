class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, area = 0;
        while(left < right)
        {
            area = max(min(height[left], height[right]) * (right-left), area);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};