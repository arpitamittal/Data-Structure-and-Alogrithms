class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
          int total = 0;
          int len = 0;
          for(int i : nums) total += i;
          if(total == x) return size;
          int need = total - x;
          int i = 0 , j = 0;
          int sum = 0;
          while( j < size ) {
                sum += nums[j];  
                while(i < j && sum > need){
                        sum -= nums[i++];
                }
                if(sum == need){
                    
                    len = max(len, j-i+1);
                }
                j++;
          } 
          if(len == 0) return -1;  
          return size-len;
    }
};