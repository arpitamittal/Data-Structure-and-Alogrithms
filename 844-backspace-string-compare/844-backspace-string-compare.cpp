class Solution {
public:
   
    bool backspaceCompare(string s, string t) {
       
        stack<char> st1, st2;
        for(auto it : s)
        {
            if(it == '#' && st1.size() != 0)
                st1.pop();
            else if(it != '#')
                st1.push(it);
        }
        for(auto it : t)
        {
            if(it == '#' && st2.size() != 0)
                st2.pop();
            else if(it != '#')
                st2.push(it);
        }
        return (st1 == st2);
    }
};