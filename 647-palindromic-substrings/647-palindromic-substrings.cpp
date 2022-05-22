class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int count = 0;
        for(int i=0; i<size; i++)
        {
            int x = i-1, y = i+1;
            count++;
            while(x>=0 && y<size && s[x]==s[y])
            {
                count++;
                x--;
                y++;
            }
            x = i, y = i+1;
             while(x>=0 && y<size && s[y]==s[x])
            {
                count++;
                x--;
                y++;
            }
        }
        return count;
    }
};