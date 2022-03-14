class Solution {
public:
    string simplifyPath(string path) {
        string s;
        vector<string> st;
        path.push_back('/');
        for(auto & c : path)
        {
            if(c == '/')
            {
                if(s.empty()) continue;
                if(s == ".." && !st.empty()) st.pop_back();
                else if(s != "." and s != "..") st.push_back(s);
                s.clear();
            }
            else s.push_back(c);
        }
        
        string ans;
        for(auto & str : st)
        {
            ans.push_back('/');
            ans += str;
        }
        if(ans.empty())
            ans.push_back('/');
        return ans;
    }
};