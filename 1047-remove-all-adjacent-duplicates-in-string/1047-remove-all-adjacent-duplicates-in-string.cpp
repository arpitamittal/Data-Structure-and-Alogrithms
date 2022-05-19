class Solution {
public:
    /*
    abbaca
         stack :- a
                  a  b
                  a      b  b
                         a  a
                  c  
                  c  a
    azxxzy
         stack :- a
                  a  z
                  a  z  x
                  a  z       x  x
                  a          z  z  
                  a  y
    
    */
    string removeDuplicates(string str) {
        stack<int> s;
        for(auto it : str)
        {
            if(s.empty()) s.push(it);
            else
            {
                if(s.top() == it)
                    s.pop();
                else
                    s.push(it);
            }
        }
        string ans;
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};