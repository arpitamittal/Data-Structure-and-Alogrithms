class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> take(n, true);
        stack<int> indices;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                indices.push(i);
            }
            else if(s[i] == ')')
            {
                if(!indices.empty())
                    indices.pop();
                else
                    take[i] = false;
            }
        }
        while(!indices.empty())
        {
            take[indices.top()] = false;
            indices.pop();
        }
        string ans;
        for(int i=0; i<n; i++)
        {
            if(take[i])
                ans.push_back(s[i]);
        }
        return ans;
    }
};