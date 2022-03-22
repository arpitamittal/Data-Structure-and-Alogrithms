class Solution {
public:
    string getSmallestString(int n, int k) {
        string str = "";
        for(int i=0; i<n; i++) str += 'a';
        k = k-n;
        for(int i=n-1; i>=0; i--)
        {
            if(k == 0) break;
            else if(k < 25)
            {
                str[i] = (char)('a' + k);
                k = 0;
            }
            else
            {
                str[i] = (char)('a' + 25);
                k -= 25;
            }
        }
        return str;
    }
};