class Solution {
public:
    string removeDuplicates(string s, int k) {
       int size = s.size(), count = 0;
        stack<pair<char, int>> st;
        for(auto val : s)
        {
            if(!st.empty())
            {
                if(st.top().first != val)
                {
                    st.push({val, 1});
                }
                else
                {
                    int count = st.top().second;
                    st.push({val, count+1});
                    if(count+1 == k)
                    {
                        while(!st.empty() && st.top().first == val)
                        {
                            st.pop();
                        }
                    }
                }
            }
            else
            {
                st.push({val, 1});
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};