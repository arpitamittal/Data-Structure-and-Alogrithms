class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size == 0) return 0;
        vector<int> prefix(size) ,suffix(size);
        prefix[0] = height[0];
        suffix[size-1] = height[size-1];
        for(int i=1; i<size; i++)
            prefix[i] = max(prefix[i-1], height[i]);
        for(int i =size-2; i>=0; i--)
            suffix[i] = max(suffix[i+1], height[i]);
        int ans = 0; 
        for(int i=0; i<size-1; i++)
        {
            ans += (min(prefix[i], suffix[i]) - height[i]);
        }
        return ans;
    }
};