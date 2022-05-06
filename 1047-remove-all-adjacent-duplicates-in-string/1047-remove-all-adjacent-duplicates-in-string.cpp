class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(st.top() != s[i])
                st.push(s[i]);
            else if(st.top() == s[i])
                st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*

 c a
 a  y

*/