class Solution {
public:
    /*
    3[a]2[bc] -> 
      a a a bc bc 
      3[a2 [c] ]
      acc acc acc
        
      98
      def2(3(aaa(bbb5(ccc6(ddd7(eee)te)ty)ui)qq)ppp)abc
      
      
    */
    string decodeString(string str) {
        stack<char> st;
        string ans;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == ']')
            {
                string newSubstring ="";
                while(st.top()!= '[')
                {
                    newSubstring.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string digits = "";
                while(!st.empty() and st.top() >= '0' and st.top() <= '9' )
                {
                    digits.push_back(st.top());
                    st.pop();
                }
                reverse(digits.begin(), digits.end());
                reverse(newSubstring.begin(), newSubstring.end());
                int factor = stoi(digits);
                while(factor--)
                {
                     for(int j=0; j<newSubstring.length(); j++) st.push(newSubstring[j]);
                }
            }
            else
                st.push(str[i]);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};