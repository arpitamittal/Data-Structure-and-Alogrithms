class Solution {
public:
    bool isPalindrome(string s, int left, int right, int count)
    {
        if(count > 1) return false;
        
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return (isPalindrome(s, left+1, right, count+1) || isPalindrome(s, left, right-1, count+1));
        }
        return true;
    }
    bool validPalindrome(string s) {
       int count = 0, left = 0, right = s.size()-1;
       return isPalindrome(s, left, right, count);
    }
};