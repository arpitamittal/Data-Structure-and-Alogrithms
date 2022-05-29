/*

        while(left<right){
            if(height[left]<=height[right]){
                if(left_max>height[left]){
                    ans += (left_max-height[left]);
                }
                else{
                    left_max=height[left];
                }
                left++;
            }
            else{
                if(right_max>height[right]){
                    ans += (right_max-height[right]);
                }
                else{
                    right_max=height[right];
                }
                right--;
            }
        }
        return ans;*/
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size == 0) return 0;
        int left = 0, right = size-1, leftMax = 0, rightMax = 0, ans = 0;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] > leftMax)
                    leftMax = height[left];
                else 
                    ans += (leftMax - height[left]);
                left++;
            }
            else
            {
                if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    ans += (rightMax - height[right]);
                right--;
            }
        }
        return ans;
    }
};