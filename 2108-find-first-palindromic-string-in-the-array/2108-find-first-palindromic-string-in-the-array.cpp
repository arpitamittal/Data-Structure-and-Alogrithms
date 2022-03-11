class Solution {
public:
    bool palindrome(string s)
    {
        string p = s;
        reverse(p.begin(), p.end());
        if(s == p) return true;
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        int size = words.size();
        string ans = "";
        for(int i=0; i<size; i++)
        {
             if( palindrome(words[i]) == true)   return words[i]; 
        }            
        return ans;
    }
};